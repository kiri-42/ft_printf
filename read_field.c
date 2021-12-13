/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:01:42 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 18:01:43 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	read_field(const char *fmt, t_flags *flags)
{
	char	*save;

	save = (char *)fmt;
	flags->field = 0;
	while (*fmt - '0' >= 0 && *fmt - '0' <= 9)
	{
		flags->field = flags->field * 10 + (*fmt - '0');
		fmt++;
	}
	fmt--;
	return (fmt - save);
}
