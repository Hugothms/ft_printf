# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 13:45:08 by hthomas           #+#    #+#              #
#    Updated: 2019/12/04 16:34:53 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
CFLAGS += -Wall -Werror -Wextra -pedantic -g -fsanitize=address
LDFLAGS +=  -fsanitize=address

SRCS = 	ft_printf.c			\
		s_printf_utils.c	\
		ft_char.c			\
		ft_hex.c			\
		ft_integer.c		\
		ft_pointer.c		\
		ft_string.c			\
		ft_unsigned_int.c	\
		ft_put_zeros.c		\
		ft_flags.c			\
		ft_atoi_no_sign.c


OBJS = $(SRCS:.c=.o)
LIB = libftprintf.a
LIBFT = libft.a
LIBFTDIR = libft/
MAKE = make
EXEC = test.out

all:	$(LIB)

$(LIB): $(LIBFT) $(OBJS)
	ar rc $@ $^
	ranlib $@

$(LIBFT): $(LIBFTDIR)*.c $(LIBFTDIR)*.h
	cd $(LIBFTDIR) && $(MAKE)
	mv $(LIBFTDIR)$@ .

clean:
	cd $(LIBFTDIR) && $(MAKE) clean
	rm -rf $(OBJS) $(LIBFT)

fclean:	clean
	cd $(LIBFTDIR) && $(MAKE) fclean
	rm -f $(LIB)

re:		fclean all



HEADER = ft_printf.h

test: $(EXEC)
	./$<

$(EXEC): $(SRCS) main.c $(LIBFT) $(HEADER)
	$(C) $(CFLAGS) -I$(HEADER) -o $@ $(SRCS) main.c $(LIBFT)
