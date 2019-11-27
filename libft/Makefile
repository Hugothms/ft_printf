# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 11:49:24 by hthomas           #+#    #+#              #
#    Updated: 2019/11/27 13:52:39 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libft.a
OBJS		=	${SRCS:.c=.o}
INCLUDES	=	libft.h
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRCS 		=	ft_memset.c			\
				ft_bzero.c			\
				ft_memcpy.c			\
				ft_memccpy.c		\
				ft_memmove.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_strlen.c			\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strncmp.c		\
				ft_strnstr.c		\
				ft_strlcpy.c		\
				ft_strlcat.c		\
				ft_atoi.c			\
				ft_calloc.c			\
				ft_strdup.c			\
				ft_substr.c			\
				ft_putnbr_fd.c		\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_strmapi.c		\
				ft_split.c			\
				ft_strtrim.c		\
				ft_itoa.c			\
				ft_strjoin.c		\
				ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_putchar.c		\
				ft_putstr.c			\
				ft_putnbr.c			\
				ft_strcmp.c			\
				ft_strstr.c			\
				ft_strcat.c			\
				ft_strmap.c			\
				ft_nsplit.c			\
				ft_strjoin_sep.c


all:		$(NAME)

$(NAME):	${OBJS}
	ar rc	$(NAME) ${OBJS}
	ranlib	$(NAME)

.c.o:
	${CC} ${CFLAGS} -I $(INCLUDES) -c $< -o ${<:.c=.o}

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
