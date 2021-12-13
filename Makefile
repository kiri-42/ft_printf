NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c print_char.c print_nbr.c print_nbr_hex.c \
		print_nbr_lhex.c print_nbr_ui.c print_ptr.c print_str.c \
		ft_strdup.c ft_strlen.c main_printf.c print_c.c print_di.c \
		print_lx.c print_p.c print_par.c print_s.c print_space.c print_u.c print_x.c \
		print_zero.c read_accurasy.c read_field.c make_flags.c read_star_accurasy.c \
		read_star_field.c print_di_exception.c print_p_exception.c \
		print_s_dot_zero.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $@ $^

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus
