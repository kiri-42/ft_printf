/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:01:19 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 23:36:49 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_digit(unsigned int arg)
{
	int	putlen;

	if (arg == 0)
		return (1);
	putlen = 0;
	while (arg > 0)
	{
		arg /= 16;
		putlen++;
	}
	return (putlen);
}

static int	print_minus_flag(t_flags *flags, int digit, unsigned int arg)
{
	int	putlen;

	putlen = 0;
	if (flags->sharp == 1 && arg != 0)
		putlen += print_str("0x", 1, 2);
	putlen += print_nbr_hex(arg, 1, flags->accurasy - digit);
	if (flags->field > digit && flags->field > flags->accurasy)
	{
		if (digit > flags->accurasy)
			putlen += print_space(1, flags->field - digit);
		else
			putlen += print_space(1, flags->field - flags->accurasy);
	}
	return (putlen);
}

static int	print_zero_flag(t_flags *flags, int digit, unsigned int arg)
{
	int	putlen;

	putlen = 0;
	if (flags->sharp == 1 && arg != 0)
		putlen += print_str("0x", 1, 2);
	putlen += print_nbr_hex(arg, 1, flags->field - digit);
	return (putlen);
}

static int	print_default(t_flags *flags, int digit, unsigned int arg)
{
	int	putlen;

	putlen = 0;
	if (flags->field > digit && flags->field > flags->accurasy)
	{
		if (digit > flags->accurasy)
			putlen += print_space(1, flags->field - digit);
		else
			putlen += print_space(1, flags->field - flags->accurasy);
	}
	if (flags->sharp == 1 && arg != 0)
		putlen += print_str("0x", 1, 2);
	putlen += print_nbr_hex(arg, 1, flags->accurasy - digit);
	return (putlen);
}

int	print_x(t_flags *flags, va_list ap)
{
	unsigned int	arg;
	int				digit;
	int				putlen;

	if (flags == NULL)
		return (0);
	arg = (unsigned int)va_arg(ap, unsigned int);
	digit = get_digit(arg);
	if (flags->sharp == 1 && arg != 0)
		flags->field -= 2;
	putlen = 0;
	if (flags->dot == 1 && flags->accurasy == 0 && arg == 0)
		putlen += print_space(1, flags->field);
	else if (flags->minus == 1)
		putlen += print_minus_flag(flags, digit, arg);
	else if (flags->zero == 1 && flags->dot == 0)
		putlen += print_zero_flag(flags, digit, arg);
	else
		putlen += print_default(flags, digit, arg);
	return (putlen);
}
