/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_exception.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 21:00:15 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/17 21:02:35 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p_exception(t_flags *flags)
{
	int	putlen;

	putlen = 0;
	if (flags->minus == 1)
	{
		putlen += print_str("0x", 1, 2);
		putlen += print_space(1, flags->field - 2);
	}
	else
	{
		putlen += print_space(1, flags->field - 2);
		putlen += print_str("0x", 1, 2);
	}
	return (putlen);
}
