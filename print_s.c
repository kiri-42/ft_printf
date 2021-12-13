/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:00:44 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/17 21:18:15 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	null_check(char **arg)
{
	int	null_flag;

	null_flag = 0;
	if (*arg == NULL)
	{
		*arg = ft_strdup("(null)");
		if (*arg == NULL)
			return (-1);
		null_flag = 1;
	}
	return (null_flag);
}

static int	print_minus_flag(t_flags *flags, char *arg, int slen)
{
	int	putlen;

	putlen = 0;
	putlen += print_str(arg, 1, flags->accurasy);
	if (slen >= flags->accurasy)
		putlen += print_space(1, flags->field - flags->accurasy);
	else
		putlen += print_space(1, flags->field - slen);
	return (putlen);
}

static int	print_zero_flag(t_flags *flags, char *arg, int slen)
{
	int	putlen;

	putlen = 0;
	if (slen >= flags->accurasy)
		putlen += print_zero(1, flags->field - flags->accurasy);
	else
		putlen += print_zero(1, flags->field - slen);
	putlen += print_str(arg, 1, flags->accurasy);
	return (putlen);
}

static int	print_default(t_flags *flags, char *arg, int slen)
{
	int	putlen;

	putlen = 0;
	if (slen >= flags->accurasy)
		putlen += print_space(1, flags->field - flags->accurasy);
	else
		putlen += print_space(1, flags->field - slen);
	putlen += print_str(arg, 1, flags->accurasy);
	return (putlen);
}

int	print_s(t_flags *flags, va_list ap)
{
	char	*arg;
	int		slen;
	int		putlen;
	int		free_flag;

	if (flags == NULL)
		return (0);
	arg = (char *)va_arg(ap, char *);
	free_flag = null_check(&arg);
	if (free_flag == -1)
		return (0);
	slen = (int)ft_strlen(arg);
	putlen = 0;
	if (flags->dot == 0)
		putlen += print_s_dot_zero(flags, arg, slen);
	else if (flags->minus == 1)
		putlen += print_minus_flag(flags, arg, slen);
	else if (flags->zero == 1)
		putlen += print_zero_flag(flags, arg, slen);
	else
		putlen += print_default(flags, arg, slen);
	if (free_flag)
		free(arg);
	return (putlen);
}
