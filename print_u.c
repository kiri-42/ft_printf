/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:01:06 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 18:01:07 by tkirihar         ###   ########.fr       */
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
		arg /= 10;
		putlen++;
	}
	return (putlen);
}

static int	print_minus_flag(t_flags *flags, int digit, unsigned int udec)
{
	int	putlen;

	putlen = 0;
	putlen += print_nbr_ui(udec, 1, flags->accurasy - digit);
	if (flags->field > digit && flags->field > flags->accurasy)
	{
		if (digit > flags->accurasy)
			putlen += print_space(1, flags->field - digit);
		else
			putlen += print_space(1, flags->field - flags->accurasy);
	}
	return (putlen);
}

static int	print_zero_flag(t_flags *flags, int digit, unsigned int udec)
{
	int	putlen;

	putlen = 0;
	putlen += print_nbr_ui(udec, 1, flags->field - digit);
	return (putlen);
}

static int	print_default(t_flags *flags, int digit, unsigned int udec)
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
	putlen += print_nbr_ui(udec, 1, flags->accurasy - digit);
	return (putlen);
}

int	print_u(t_flags *flags, va_list ap)
{
	unsigned int	udec;
	int				digit;
	int				putlen;

	if (flags == NULL)
		return (0);
	udec = (unsigned int)va_arg(ap, unsigned int);
	digit = get_digit(udec);
	putlen = 0;
	if (flags->dot == 1 && flags->accurasy == 0 && udec == 0)
		putlen += print_space(1, flags->field);
	else if (flags->minus == 1)
		putlen += print_minus_flag(flags, digit, udec);
	else if (flags->zero == 1 && flags->dot == 0)
		putlen += print_zero_flag(flags, digit, udec);
	else
		putlen += print_default(flags, digit, udec);
	return (putlen);
}
