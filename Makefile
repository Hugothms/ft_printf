# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 13:45:08 by hthomas           #+#    #+#              #
#    Updated: 2019/12/05 16:36:46 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
CFLAGS += -Wall -Werror -Wextra -pedantic -g -fsanitize=address
LDFLAGS +=  -fsanitize=address

SRCS = 	ft_printf.c			\
		ft_s_printf_utils.c	\
		ft_char.c			\
		ft_hex.c			\
		ft_integer.c		\
		ft_pointer.c		\
		ft_string.c			\
		ft_unsigned_int.c	\
		ft_width.c			\
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
	cp $(LIBFTDIR)$@ .

clean:
	cd $(LIBFTDIR) && $(MAKE) clean
	rm -rf $(OBJS) $(LIBFT) $(EXEC)

fclean:	clean
	cd $(LIBFTDIR) && $(MAKE) fclean
	rm -f $(LIB)

re:		fclean all



HEADER = ft_printf.h

test: $(EXEC)
	./$<

$(EXEC): $(SRCS) main.c $(LIBFT) $(HEADER)
	$(C) $(CFLAGS) -I$(HEADER) -o $@ $(SRCS) main.c $(LIBFT)
