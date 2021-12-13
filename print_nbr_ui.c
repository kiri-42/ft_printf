/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_ui.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:00:10 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 18:00:11 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr_ui(unsigned int n, int fd, int zero)
{
	unsigned int	div;
	unsigned int	mod;
	int				putlen;

	putlen = 0;
	mod = n % 10 + '0';
	div = n / 10;
	if (div > 0)
		putlen += print_nbr_ui(div, fd, zero);
	if (div == 0)
		putlen += print_zero(fd, zero);
	putlen += print_char(mod, 1);
	return (putlen);
}
