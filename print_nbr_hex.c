/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:59:56 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 17:59:57 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr_hex(unsigned int n, int fd, int zero)
{
	unsigned int	mod;
	unsigned int	div;
	unsigned char	uc;
	int				putlen;

	putlen = 0;
	mod = n % 16;
	if (mod < 10)
		uc = mod + '0';
	else
		uc = 'a' + (mod - 10);
	div = n / 16;
	if (div > 0)
		putlen += print_nbr_hex(div, fd, zero);
	if (div == 0)
		putlen += print_zero(fd, zero);
	putlen += print_char(uc, 1);
	return (putlen);
}
