/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:58:58 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 17:58:59 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	input_percent_part(const char *fmt, va_list ap,
								t_flags *flags, int *putlen)
{
	int		diff_fmt;
	char	*start;

	start = (char *)fmt;
	fmt++;
	if (*fmt == '\0')
		return (-1);
	else if (*fmt == '%')
	{
		*putlen += print_char('%', 1);
		return (-2);
	}
	else
	{
		diff_fmt = make_flags(flags, fmt, ap);
		if (diff_fmt == -1)
			return (-1);
		fmt += diff_fmt;
	}
	return (fmt - start);
}

static int	output_percent_part(t_flags *flags, va_list ap)
{
	int	putlen;

	putlen = 0;
	if (flags->modifier == '%')
		putlen += print_par(flags);
	else if (flags->modifier == 'd' || flags->modifier == 'i')
		putlen += print_di(flags, ap);
	else if (flags->modifier == 'u')
		putlen += print_u(flags, ap);
	else if (flags->modifier == 'x')
		putlen += print_x(flags, ap);
	else if (flags->modifier == 'X')
		putlen += print_lx(flags, ap);
	else if (flags->modifier == 'p')
		putlen += print_p(flags, ap);
	else if (flags->modifier == 's')
		putlen += print_s(flags, ap);
	else if (flags->modifier == 'c')
		putlen += print_c(flags, ap);
	return (putlen);
}

void	main_printf(const char *fmt, va_list ap, int *putlen)
{
	int		diff_fmt;
	t_flags	flags;

	while (*fmt != '\0')
	{
		if (*fmt != '%')
			*putlen += print_char(*fmt, 1);
		else
		{
			diff_fmt = input_percent_part(fmt, ap, &flags, putlen);
			if (diff_fmt == -1)
				break ;
			if (diff_fmt == -2)
			{
				fmt += 2;
				continue ;
			}
			fmt += diff_fmt;
			if (diff_fmt > 0)
				*putlen += output_percent_part(&flags, ap);
		}
		fmt++;
	}
	return ;
}
