# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 13:45:08 by hthomas           #+#    #+#              #
#    Updated: 2019/12/01 15:37:45 by hthomas          ###   ########.fr        #
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
LIBFT = libft.a
LIBFTDIR = libft/
MAKE = make

all:	$(LIB)

$(LIB): $(LIBFT) $(OBJ)
	ar rc $(LIB) $(LIBFT) ${OBJS}
	ranlib $(LIB)

$(LIBFT):
	cd $(LIBFTDIR) && $(MAKE)
	mv $(LIBFTDIR)$(LIBFT) .

clean:
	cd $(LIBFTDIR) && $(MAKE) clean
	rm -rf $(OBJ) $(LIBFT)

fclean:	clean
	cd $(LIBFTDIR) && $(MAKE) fclean
	rm -f $(LIB)

re:		fclean all

test: $(LIBFT)
	$(C) $(SRC) main.c $(LIBFT)
	#clear
	./a.out