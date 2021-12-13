/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:54:25 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 17:54:40 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int n, int fd, int zero)
{
	unsigned int	tmp;
	int				putlen;
	int				div;
	int				mod;

	putlen = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		putlen++;
		tmp = n * -1;
	}
	else
		tmp = n;
	mod = tmp % 10 + '0';
	div = tmp / 10;
	if (div > 0)
		putlen += print_nbr(div, fd, zero);
	if (div == 0)
		putlen += print_zero(fd, zero);
	write(fd, &mod, 1);
	putlen++;
	return (putlen);
}
