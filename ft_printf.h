/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:58:13 by tkirihar          #+#    #+#             */
/*   Updated: 2021/10/17 21:16:46 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_flags
{
	char	modifier;
	int		plus;
	int		minus;
	int		zero;
	int		sharp;
	int		space;
	int		field;
	int		dot;
	int		accurasy;
}				t_flags;

int		ft_printf(const char *fmt, ...);
void	main_printf(const char *fmt, va_list ap, int *putlen);
int		make_flags(t_flags *flags, const char *fmt, va_list ap);
void	read_star_field(t_flags *flags, va_list ap);
int		read_field(const char *fmt, t_flags *flags);
int		read_accurasy(const char *fmt, t_flags *flags, va_list ap);
void	read_star_accurasy(t_flags *flags, va_list ap);
int		print_char(char c, int fd);
int		print_space(int fd, int size);
int		print_zero(int fd, int size);
int		print_par(t_flags *flags);
int		print_di(t_flags *flags, va_list ap);
int		print_di_exception(t_flags *flags);
int		print_u(t_flags *flags, va_list ap);
int		print_x(t_flags *flags, va_list ap);
int		print_lx(t_flags *flags, va_list ap);
int		print_p(t_flags *flags, va_list ap);
int		print_p_exception(t_flags *flags);
int		print_s(t_flags *flags, va_list ap);
int		print_s_dot_zero(t_flags *flags, char *arg, int slen);
int		print_c(t_flags *flags, va_list ap);
int		print_nbr_lhex(unsigned int n, int fd, int zero);
int		print_nbr_hex(unsigned int n, int fd, int zero);
int		print_nbr(int n, int fd, int zero);
int		print_nbr_ui(unsigned int n, int fd, int zero);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *src);
int		print_str(char *s, int fd, int accurasy);
int		print_ptr(unsigned long n, int fd, int zero);
int		print_str(char *s, int fd, int accurasy);

#endif
