/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_dot_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 21:13:08 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/17 21:14:51 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s_dot_zero(t_flags *flags, char *arg, int slen)
{
	int	putlen;

	putlen = 0;
	if (flags->minus == 1)
	{
		putlen += print_str(arg, 1, slen);
		putlen += print_space(1, flags -> field - slen);
	}
	else if (flags->zero == 1)
	{
		putlen += print_zero(1, flags->field - slen);
		putlen += print_str(arg, 1, slen);
	}
	else
	{
		putlen += print_space(1, flags->field - slen);
		putlen += print_str(arg, 1, slen);
	}
	return (putlen);
}
