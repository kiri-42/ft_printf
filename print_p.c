/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:53:57 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/17 20:57:50 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_digit(unsigned long arg)
{
	int	digit;

	if (arg == 0)
		return (1);
	digit = 0;
	while (arg > 0)
	{
		arg /= 16;
		digit++;
	}
	return (digit);
}

static int	print_minus_flag(t_flags *flags, int digit, unsigned long arg)
{
	int	putlen;

	putlen = 0;
	flags->field -= 2;
	putlen += print_ptr(arg, 1, flags->accurasy - digit);
	if (flags->field > digit && flags->field > flags->accurasy)
	{
		if (digit > flags->accurasy)
			putlen += print_space(1, flags->field - digit);
		else
			putlen += print_space(1, flags->field - flags->accurasy);
	}
	return (putlen);
}

static int	print_zero_flag(t_flags *flags, int digit, unsigned long arg)
{
	int	putlen;

	putlen = 0;
	flags->field -= 2;
	putlen += print_ptr(arg, 1, flags->field - digit);
	return (putlen);
}

static int	print_default(t_flags *flags, int digit, unsigned long arg)
{
	int	putlen;

	putlen = 0;
	flags->field -= 2;
	if (flags->field > digit && flags->field > flags->accurasy)
	{
		if (digit > flags->accurasy)
			putlen += print_space(1, flags->field - digit);
		else
			putlen += print_space(1, flags->field - flags->accurasy);
	}
	putlen += print_ptr(arg, 1, flags->accurasy - digit);
	return (putlen);
}

int	print_p(t_flags *flags, va_list ap)
{
	unsigned long	arg;
	int				digit;
	int				putlen;

	if (flags == NULL)
		return (0);
	arg = (unsigned long)va_arg(ap, unsigned long);
	digit = get_digit(arg);
	putlen = 0;
	if (flags->dot == 1 && flags->accurasy == 0 && arg == 0)
		putlen += print_p_exception(flags);
	else if (flags->minus == 1)
		putlen += print_minus_flag(flags, digit, arg);
	else if (flags->zero == 1 && flags->dot == 0)
		putlen += print_zero_flag(flags, digit, arg);
	else
		putlen += print_default(flags, digit, arg);
	return (putlen);
}
