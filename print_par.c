/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_par.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:00:27 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 18:00:28 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_par(t_flags *flags)
{
	int	putlen;

	if (flags == NULL)
		return (0);
	putlen = 0;
	if (flags->minus == 1)
	{
		putlen += print_char('%', 1);
		putlen += print_space(1, flags->field - 1);
	}
	else if (flags->zero == 1)
	{
		putlen += print_zero(1, flags->field - 1);
		putlen += print_char('%', 1);
	}
	else
	{
		putlen += print_space(1, flags->field - 1);
		putlen += print_char('%', 1);
	}
	return (putlen);
}
