/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:59:12 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 17:59:13 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(t_flags *flags, va_list ap)
{
	unsigned char		arg;
	int					clen;
	int					putlen;

	if (flags == NULL)
		return (0);
	arg = (unsigned char)va_arg(ap, int);
	clen = 1;
	putlen = 0;
	if (flags -> minus == 1)
	{
		putlen += print_char(arg, 1);
		putlen += print_space(1, flags -> field - clen);
	}
	else if (flags -> zero == 1)
	{
		putlen += print_zero(1, flags -> field - clen);
		putlen += print_char(arg, 1);
	}
	else
	{
		putlen += print_space(1, flags -> field - clen);
		putlen += print_char(arg, 1);
	}
	return (putlen);
}
