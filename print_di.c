/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:59:36 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/17 21:00:24 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_digit(int arg)
{
	int	digit;

	if (arg == 0)
		return (1);
	digit = 0;
	while (arg != 0)
	{
		arg /= 10;
		digit++;
	}
	return (digit);
}

static int	print_minus_flag(t_flags *flags, int digit, int arg)
{
	int	putlen;

	putlen = 0;
	if (arg < 0)
		flags->field--;
	if (arg >= 0)
	{
		if (flags->plus == 1)
			putlen += print_char('+', 1);
		else if (flags->space == 1)
			putlen += print_char(' ', 1);
	}
	putlen += print_nbr(arg, 1, flags->accurasy - digit);
	if (flags->field > digit && flags->field > flags->accurasy)
	{
		if (digit > flags->accurasy)
			putlen += print_space(1, flags->field - digit);
		else
			putlen += print_space(1, flags->field - flags->accurasy);
	}
	return (putlen);
}

static int	print_zero_flag(t_flags *flags, int digit, int arg)
{
	int	putlen;

	putlen = 0;
	if (arg < 0)
		flags->field--;
	if (arg >= 0)
	{
		if (flags->plus == 1)
			putlen += print_char('+', 1);
		else if (flags->space == 1)
			putlen += print_char(' ', 1);
	}
	putlen += print_nbr(arg, 1, flags->field - digit);
	return (putlen);
}

static int	print_default(t_flags *flags, int digit, int arg)
{
	int	putlen;

	putlen = 0;
	if (arg < 0)
		flags->field--;
	if (flags->field > digit && flags->field > flags->accurasy)
	{
		if (digit > flags->accurasy)
			putlen += print_space(1, flags->field - digit);
		else
			putlen += print_space(1, flags->field - flags->accurasy);
	}
	if (arg >= 0)
	{
		if (flags->plus == 1)
			putlen += print_char('+', 1);
		else if (flags->space == 1)
			putlen += print_char(' ', 1);
	}
	putlen += print_nbr(arg, 1, flags->accurasy - digit);
	return (putlen);
}

int	print_di(t_flags *flags, va_list ap)
{
	int	arg;
	int	digit;
	int	putlen;

	if (flags == NULL)
		return (0);
	arg = (int)va_arg(ap, int);
	digit = get_digit(arg);
	if ((flags->plus == 1 || flags->space == 1) && arg >= 0)
		flags->field -= 1;
	putlen = 0;
	if (flags->dot == 1 && flags->accurasy == 0 && arg == 0)
		putlen += print_di_exception(flags);
	else if (flags->minus == 1)
		putlen += print_minus_flag(flags, digit, arg);
	else if (flags->zero == 1 && flags->dot == 0)
		putlen += print_zero_flag(flags, digit, arg);
	else
		putlen += print_default(flags, digit, arg);
	return (putlen);
}
