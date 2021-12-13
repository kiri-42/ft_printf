/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_lhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:00:03 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 18:00:04 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr_lhex(unsigned int n, int fd, int zero)
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
		uc = 'A' + (mod - 10);
	div = n / 16;
	if (div > 0)
		putlen += print_nbr_lhex(div, fd, zero);
	if (div == 0)
		putlen += print_zero(fd, zero);
	putlen += print_char(uc, 1);
	return (putlen);
}
