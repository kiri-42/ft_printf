/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:00:57 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 18:00:58 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *s, int fd, int accurasy)
{
	int	slen;
	int	ret;

	if (s == NULL)
		return (0);
	slen = ft_strlen(s);
	if (slen > accurasy)
		ret = accurasy;
	else
		ret = slen;
	write(fd, s, ret);
	return (ret);
}
