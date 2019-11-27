# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 13:45:08 by hthomas           #+#    #+#              #
#    Updated: 2019/11/27 18:17:39 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = ft_printf.c
OBJ = $(SRC:.c=.o)
LIB = libftprintf.a
LBLIBS = libft.a
LIBDIR = libft/
MAKE = make

all:	$(LIB)

$(LIB): $(OBJ)
	cd libft && $(MAKE)
	mv $(LIBDIR)$(LBLIBS) .
	ar rc $(LIB) $(LBLIBS) ${OBJS}
	ranlib $(LIB)

clean:
	rm -rf $(OBJ) $(LBLIBS)

fclean:	clean
	rm -f $(LIB)

re:		fclean all
