/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di_exception.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:40:44 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/17 21:20:46 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_di_exception(t_flags *flags)
{
	int	putlen;

	putlen = 0;
	if (flags->minus == 1)
	{
		if (flags->plus == 1)
			putlen += print_char('+', 1);
		else if (flags->space == 1)
			putlen += print_char(' ', 1);
		putlen += print_space(1, flags->field);
	}
	else
	{
		putlen += print_space(1, flags->field);
		if (flags->plus == 1)
			putlen += print_char('+', 1);
		else if (flags->space == 1)
			putlen += print_char(' ', 1);
	}
	return (putlen);
}
