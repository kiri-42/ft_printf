/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:57:55 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 17:57:59 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int		putlen;
	va_list	ap;

	if (fmt == NULL)
		return (0);
	va_start(ap, fmt);
	putlen = 0;
	main_printf(fmt, ap, &putlen);
	va_end(ap);
	return (putlen);
}
