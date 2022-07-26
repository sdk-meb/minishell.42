NAME = minishell
CC = gcc
CFLAGS =  -Wall -Wextra -Werror
LINKER= -lreadline
INC=# '-I$(shell pwd)/lib'

RED = \033[0;31m
GREEN = \033[0;32m
NO_COLOR = \033[0m

MAIN = main.c
SRC_PARSER = 
SRC_SUBSYSTEMS = 
SRC_EXECUTOR = 

MAIN_O = $(ls
:.c=.o)
OBJ_PARSER = $(SRC_PARSER:.c=.o)
OBJ_SUBSYSTEMS = $(SRC_SUBSYSTEMS:.c=.o)
OBJ_EXECUTOR = $(SRC_EXECUTOR:.c=.o)

%.o:%.c  lib/head.h
	@${CC} ${CFLAGS} -o $@ -c $<

all: ${NAME}

$(NAME): ${MAIN_O} $(OBJ_PARSER)
	@${CC} ${CFLAGS} ${LINKER} ${MAIN_O} $(OBJ_PARSER) -o ${NAME}
	@echo "${GREEN} • Now you can run the exucitable file ./${NAME}${NO_COLOR}"

bonus:


clean:
	@rm -rf ${OBJ_FILES}
	@echo "${RED} • ALL object files were deleted${NO_COLOR}"

fclean: clean
	@rm -rf ${NAME}
	@echo "${RED} • The executed file was removed${NO_COLOR}"

re: fclean all

.PHONY: re fclean clean all