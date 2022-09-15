NAME	= minishell
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LINKER	= -lreadline '-L$(shell brew --prefix readline)/lib'

INC		= '-I$(shell pwd)/Include' '-I$(shell pwd)/libft'\
			'-I$(shell brew --prefix readline)/include'
LIBFT 	= libft/libft.a
INCLUDE = Include/Exec.h Include/Parser.h Include/Subsystem.h Include/minishell.h

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
SRC_PARSER		= Parser/ast.c Parser/Auxiliaries_files/file1.c Parser/call_shell.c Parser/check_syntax_errors/check.c\
					Parser/check_syntax_errors/check_utils.c Parser/herdoc/ft_herdoc.c Parser/herdoc/heredoc_utils.c\
					Parser/Lists/list_env.c Parser/Lists/list_tokens.c Parser/Tockenization_files/expand.c\
					Parser/Tockenization_files/expand_heredoc.c Parser/Tockenization_files/expander_utils1.c\
					Parser/Tockenization_files/expander_utils2.c Parser/Tockenization_files/repair_line.c\
					Parser/Tockenization_files/tokenize_line.c Parser/Tockenization_files/tokenizer_utils.c\
					Parser/pop_spcs.c

SRC_SUBSYSTEMS	=	Subsystems/env.c Subsystems/env1.c Subsystems/exp.c Subsystems/unset.c\
					 Subsystems/b_expr.c

SRC_EXECUTOR	= Executor/Built_cmd.c Executor/echo.c Executor/Err.c Executor/exuc.c Executor/pipe.c\
					Executor/rd_from_wr_in.c Executor/sig.c Executor/stat_loc.c Executor/terminate.c

MAIN_O				= $(MAIN:.c=.o)
OBJ_PARSER 			= $(SRC_PARSER:.c=.o)
OBJ_SUBSYSTEMS		= $(SRC_SUBSYSTEMS:.c=.o)
OBJ_EXECUTOR 		= $(SRC_EXECUTOR:.c=.o)

%.o:%.c ${INCLUDE}
	@$(CC) $(INC)  $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(LIBFT):
	@make -C libft/

$(NAME): $(LIBFT) $(MAIN_O) $(OBJ_PARSER) $(OBJ_SUBSYSTEMS) $(OBJ_EXECUTOR)
	@$(CC) $(CFLAGS) $(LINKER) $(LIBFT) -o $(NAME) $(MAIN_O) $(OBJ_PARSER) $(OBJ_SUBSYSTEMS) $(OBJ_EXECUTOR)
	@echo "${BIGreen} • An executable file has been generated $(BIYellow)./${NAME}${NO_COLOR}"

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
