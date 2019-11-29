# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 13:45:08 by hthomas           #+#    #+#              #
#    Updated: 2019/11/29 20:27:01 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = 	ft_printf.c			\
		s_printf_utils.c	\
		ft_char.c			\
		ft_hex.c			\
		ft_integer.c		\
		ft_pointer.c		\
		ft_string.c			\
		ft_unsigned_int.c

OBJ = $(SRC:.c=.o)
LIB = libftprintf.a
LBLIBS = libft.a
LIBDIR = libft/
MAKE = make

all:	$(LIB)

$(LIB): makelibft $(OBJ)
	ar rc $(LIB) $(LBLIBS) ${OBJS}
	ranlib $(LIB)

makelibft:
	cd libft && $(MAKE)
	mv $(LIBDIR)$(LBLIBS) .

clean:
	cd libft && $(MAKE) clean
	rm -rf $(OBJ) $(LBLIBS)

fclean:	clean
	cd libft && $(MAKE) fclean
	rm -f $(LIB)

re:		fclean all

test: makelibft
	$(C) $(SRC) main.c $(LBLIBS)
	#clear
	./a.out