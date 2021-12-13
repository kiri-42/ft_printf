/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:00:51 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 18:00:52 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_space(int fd, int size)
{
	int	putlen;

	putlen = 0;
	while (size > 0)
	{
		putlen += print_char(' ', fd);
		size--;
	}
	return (putlen);
}
