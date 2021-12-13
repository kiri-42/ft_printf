/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_star_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:02:02 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 18:02:03 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	read_star_field(t_flags *flags, va_list ap)
{
	int	arg;

	arg = (int)va_arg(ap, int);
	if (arg >= 0)
		flags->field = arg;
	else
	{
		flags->minus = 1;
		flags->field = arg * -1;
	}
}
