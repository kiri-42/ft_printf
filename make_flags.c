/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:56:02 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/15 17:56:06 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	initialize(t_flags *flags)
{
	flags->modifier = '\0';
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->sharp = 0;
	flags->space = 0;
	flags->field = 0;
	flags->dot = 0;
	flags->accurasy = 0;
}

char	modifier_search(const char *fmt, const char *modifier)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (fmt[i] != '\0')
	{
		j = 0;
		while (modifier[j] != '\0')
		{
			if (fmt[i] == modifier[j])
				return ((char)modifier[j]);
			j++;
		}
		i++;
	}
	return ('\0');
}

static int	read_flags(t_flags *flags, const char *fmt, va_list ap)
{
	const char	*start;

	start = fmt;
	if (*fmt == '+')
		flags->plus = 1;
	else if (*fmt == '-')
		flags->minus = 1;
	else if (*fmt == '0')
		flags->zero = 1;
	else if (*fmt == '#')
		flags->sharp = 1;
	else if (*fmt == ' ')
		flags->space = 1;
	else if (*fmt == '*')
		read_star_field(flags, ap);
	else if (*fmt - '0' >= 0 && *fmt - '0' <= 9)
		fmt += read_field(fmt, flags);
	else if (*fmt == '.')
		fmt += read_accurasy(fmt, flags, ap);
	fmt++;
	return (fmt - start);
}

int	make_flags(t_flags *flags, const char *fmt, va_list ap)
{
	char	*start;

	if (flags == NULL || fmt == NULL)
		return (-1);
	initialize(flags);
	flags->modifier = modifier_search(fmt, "cspdiuxX%");
	if (flags->modifier == '\0')
		return (-1);
	start = (char *)fmt;
	while (*fmt != flags->modifier)
		fmt += read_flags(flags, fmt, ap);
	return (fmt - start);
}
