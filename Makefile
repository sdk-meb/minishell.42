NAME     = minishell
CC       = gcc
CFLAGS   = -Wall -Wextra -Werror
LINKER   = -lreadline
INC      = '-I$(shell pwd)/lib' '-I$(shell pwd)/libft.42'

RED      = \033[0;31m
GREEN    = \033[0;32m
NO_COLOR = \033[0m

ARCHLIB  		= libft.42/libft.a
MAIN           	= main.c
SRC_PARSER     	= $(shell ls Parser/*.c)
SRC_SUBSYSTEMS 	= $(shell ls Subsystems/*.c)
SRC_EXECUTOR  	= $(shell ls Executor/*.c)

MAIN_O         	= $(MAIN:.c=.o)
OBJ_PARSER 		= $(SRC_PARSER:.c=.o)
OBJ_SUBSYSTEMS 	= $(SRC_SUBSYSTEMS:.c=.o)
OBJ_EXECUTOR 	= $(SRC_EXECUTOR:.c=.o)
OBJ_LIB			= $(shell ls Parser/*.o)


%.o:%.c  lib/head.h
	@${CC} $(INC) ${CFLAGS} -o $@ -c $<

all: ${ARCHLIB} $(OBJ_LIB) $(NAME) 

$(NAME):  ${MAIN_O} $(OBJ_PARSER) $(OBJ_EXECUTOR) 
	@${CC} ${CFLAGS} $(INC) ${LINKER} ${MAIN_O} $(OBJ_EXECUTOR) $(OBJ_PARSER) $(ARCHLIB) -o ${NAME}
	@echo "${GREEN} • Now you can run the exucitable file ./${NAME}${NO_COLOR}"

$(ARCHLIB):
	@make -C libft.42/

bonus:


clean:
	@make clean -C libft.42
	@rm -rf ${MAIN_O} $(OBJ_PARSER) $(OBJ_EXECUTOR)
	@echo "${RED} • ALL object files were deleted${NO_COLOR}"

fclean: clean
	@rm -rf ${NAME} $(ARCHLIB)
	@echo "${RED} • The executed file was removed${NO_COLOR}"

re: fclean all

.PHONY: re fclean clean all