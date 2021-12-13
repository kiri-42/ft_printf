/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:00:38 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 18:00:39 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long n, int fd, int zero)
{
	unsigned long	mod;
	unsigned long	div;
	char			c;
	int				done;

	done = 0;
	mod = n % 16;
	if (mod < 10)
		c = mod + '0';
	else
		c = 'a' + (mod - 10);
	div = n / 16;
	if (div > 0)
		done += print_ptr(div, fd, zero);
	if (div == 0)
	{
		write(fd, "0x", 2);
		done += 2;
		done += print_zero(fd, zero);
	}
	done += print_char(c, 1);
	return (done);
}
