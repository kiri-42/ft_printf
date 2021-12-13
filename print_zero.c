/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:01:29 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 18:01:30 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_zero(int fd, int size)
{
	int	putlen;

	putlen = 0;
	while (size > 0)
	{
		putlen += print_char('0', fd);
		size--;
	}
	return (putlen);
}
