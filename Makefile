NAME	= minishell
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LINKER	= -lreadline
INC		= '-I$(shell pwd)/lib' '-I$(shell pwd)/libft'
LIBFT 	= libft/libft.a

RED 		= \033[0;31m
GREEN		= \033[0;32m
NO_COLOR	= \033[0m

MAIN 			= main.c
SRC_PARSER		= #$(shell ls Parser/*.c)
SRC_SUBSYSTEMS	= #$(shell ls Subsystems/*.c)
SRC_EXECUTOR	= $(shell ls Executor/*.c)

MAIN_O				= $(MAIN:.c=.o)
OBJ_PARSER 			= $(SRC_PARSER:.c=.o)
OBJ_SUBSYSTEMS		= $(SRC_SUBSYSTEMS:.c=.o)
OBJ_EXECUTOR 		= $(SRC_EXECUTOR:.c=.o)

%.o:%.c  lib/head.h libft
	@${CC} ${INC}  ${CFLAGS} -o $@ -c $<

all: ${NAME}

$(LIBFT): 
	@make -C libft/

$(NAME): ${LIBFT} $(MAIN_O) ${OBJ_PARSER} $(OBJ_SUBSYSTEMS) $(OBJ_EXECUTOR)
	@${CC} ${CFLAGS} ${LINKER} ${LIBFT} -o ${NAME} \
	$(MAIN_O) ${OBJ_PARSER} $(OBJ_SUBSYSTEMS) $(OBJ_EXECUTOR)
	@echo "${GREEN} • Now you can run the exucitable file ./${NAME}${NO_COLOR}"

bonus:


clean:
	@rm -rf ${OBJ_PARSER} $(MAIN_O) $(OBJ_SUBSYSTEMS) $(OBJ_EXECUTOR)
	@make clean -C libft/
	@echo "${RED} • ALL object files were deleted${NO_COLOR}"

fclean: clean
	@rm -rf ${NAME}
	@rm -rf ${LIBFT}
	@echo "${RED} • The executed file was removed${NO_COLOR}"

re: fclean all

.PHONY: re fclean clean all