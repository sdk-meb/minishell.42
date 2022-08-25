NAME	= minishell
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LINKER	= -lreadline -L/goinfre/mes-sadk/homebrew/opt/readline/lib

INC		= '-I$(shell pwd)/Include' '-I$(shell pwd)/libft'\
			'-I/goinfre/mes-sadk/homebrew/opt/readline/include'
LIBFT 	= libft/libft.a

#regular colors :
RED 		= \033[0;31m
GREEN		= \033[0;32m
NO_COLOR	= \033[0m

# Bold High Intensty :
BIBlack=\033[1;90m
BIRed=\033[1;91m
BIGreen=\033[1;92m
BIYellow=\033[1;93m
BIBlue=\033[1;94m
BIPurple=\033[1;95m
BICyan=\033[1;96m
BIWhite=\033[1;97m

MAIN 			= main.c
SRC_PARSER		= $(shell find Parser -type f | grep \\.c$)
SRC_SUBSYSTEMS	= $(shell find Subsystems -type f | grep \\.c$)
SRC_EXECUTOR	= $(shell find Executor -type f | grep '\.c\>')

MAIN_O				= $(MAIN:.c=.o)
OBJ_PARSER 			= $(SRC_PARSER:.c=.o)
OBJ_SUBSYSTEMS		= $(SRC_SUBSYSTEMS:.c=.o)
OBJ_EXECUTOR 		= $(SRC_EXECUTOR:.c=.o)

%.o:%.c $(shell ls Include/*)
	@$(CC) $(INC)  $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(LIBFT):
	@make -C libft/

$(NAME): $(LIBFT) $(MAIN_O) $(OBJ_PARSER) $(OBJ_SUBSYSTEMS) $(OBJ_EXECUTOR)
	@$(CC) $(CFLAGS) $(LINKER) $(LIBFT) -o $(NAME) $(MAIN_O) $(OBJ_PARSER) $(OBJ_SUBSYSTEMS) $(OBJ_EXECUTOR)
	@echo "${BIGreen} • An executable file has been generated $(BIYellow)./${NAME}${NC}"

bonus:


clean:
	@rm -rf ${OBJ_PARSER} $(MAIN_O) $(OBJ_SUBSYSTEMS) $(OBJ_EXECUTOR)
	@make clean -C libft/
	@echo "$(BIRed) • object files has been successfully deleted${NO_COLOR}"

fclean: clean
	@rm -rf ${NAME}
	@rm -rf ${LIBFT}
	@echo "${BIRed} • The executable file has been successfuly removed${NO_COLOR}"

re: fclean all

.PHONY: re fclean clean all
