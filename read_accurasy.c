/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_accurasy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:01:36 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 18:01:37 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	read_accurasy(const char *fmt, t_flags *flags, va_list ap)
{
	char	*save;

	save = (char *)fmt;
	flags->dot = 1;
	flags->accurasy = 0;
	fmt++;
	if (*fmt == '*')
		read_star_accurasy(flags, ap);
	else
	{
		while (*fmt - '0' >= 0 && *fmt - '0' <= 9)
		{
			flags->accurasy = flags->accurasy * 10 + (*fmt - '0');
			fmt++;
		}
		fmt--;
	}
	return (fmt - save);
}
