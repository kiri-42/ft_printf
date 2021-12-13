/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_star_accurasy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:01:52 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 18:01:53 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	read_star_accurasy(t_flags *flags, va_list ap)
{
	int	arg;

	arg = (int)va_arg(ap, int);
	if (arg >= 0)
		flags->accurasy = arg;
	else
	{
		flags->dot = 0;
		flags->accurasy = 0;
	}
}
