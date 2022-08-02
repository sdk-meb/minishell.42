# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 17:37:03 by mes-sadk          #+#    #+#              #
#    Updated: 2021/11/24 17:15:20 by mes-sadk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***MAKEFILE***
#
#target : dependenses
#	action

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ =	ft_atoi.o ft_isascii.o ft_memcmp.o ft_putendl_fd.o \
		ft_strdup.o ft_strlen.o ft_strtrim.o ft_bzero.o \
		ft_isdigit.o ft_memcpy.o ft_putnbr_fd.o ft_striteri.o \
		ft_strmapi.o ft_substr.o ft_calloc.o ft_isprint.o \
		ft_memmove.o ft_putstr_fd.o ft_strjoin.o ft_strncmp.o \
		ft_tolower.o ft_isalnum.o ft_itoa.o ft_memset.o \
		ft_split.o ft_strlcat.o ft_strnstr.o ft_toupper.o \
		ft_isalpha.o ft_memchr.o ft_putchar_fd.o ft_strchr.o \
		ft_strlcpy.o ft_strrchr.o

BONUS_OBJ = ft_lstnew.o ft_lstadd_front.o ft_lstadd_back.o \
	   	ft_lstsize.o ft_lstlast.o ft_lstdelone.o \
		ft_lstclear.o ft_lstiter.o ft_lstmap.o

all: $(NAME)

$(NAME): $(OBJ) libft.h
	ar -r $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ) libft.h
	ar -r $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
