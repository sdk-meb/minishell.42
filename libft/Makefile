# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 17:37:03 by mes-sadk          #+#    #+#              #
#    Updated: 2022/08/27 22:12:12 by mes-sadk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror


RED 		= \033[0;31m
GREEN		= \033[0;32m
NO_COLOR	= \033[0m

SRC =	ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c \
		ft_strdup.c ft_strlen.c ft_strtrim.c ft_bzero.c \
		ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c \
		ft_strmapi.c ft_substr.c ft_calloc.c ft_isprint.c \
		ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c \
		ft_tolower.c ft_isalnum.c ft_itoa.c ft_memset.c \
		ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c \
		ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strchr.c \
		ft_strlcpy.c ft_strrchr.c leak_chap.c ft_strnindex.c


OBJ					= $(SRC:.c=.o)

%.o:%.c libft.h
	@${CC}   ${CFLAGS} -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ) libft.h
	@ar -rc $(NAME) $(OBJ)
	@echo "${GREEN} • libft archive file was archived ./${NAME}${NO_COLOR}"

clean:
	@rm -f $(OBJ)
	@echo "${RED} • ALL libft object files were deleted${NO_COLOR}"

fclean: clean
	@rm -f $(NAME)
	@echo "${RED} • ${NAME} file was removed${NO_COLOR}"

re: fclean all

.PHONY: all clean fclean re
