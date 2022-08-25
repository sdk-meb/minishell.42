/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:51 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/25 18:03:51 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
/*
		__E-X-E-C-U-T-I-O-N____L_I_B_R_A_R_Y_  belongs __MINISHELL__
*/

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# include <errno.h>

# include <dirent.h>
# include <fcntl.h>

# include <sys/stat.h>

# include <sys/types.h>
# include <sys/wait.h>
# include <sys/syslimits.h>
# include "minishell.h"
# include "../libft/mtypes.h"
# include "/goinfre/mes-sadk/homebrew/opt/readline/include/readline/readline.h"

/* __________________________________  */

# define HEREDOC	'H'	 /* << redirection */
# define APNDDOC	0x2E /* >> redirection  : append document */
# define glb		glb_sig(EMPTY)
/* __________________________________  */

void	pipe_x(t_cmd fd_read);
void	close_fd(int from, int to);

/* read form , write in */
void	rf_wi(t_cmd cmd);

void	ft_err(t_str str, int erno);
int		stat_loc(int statu);
int		glb_sig(int sig);

bool	bult_c(t_cmd cmd);/* exit status $? */

/* It allows to execute of a binary file to Overlay
 by a child process and not bother the parent,
 also it also duplicates output to the destination
 and input from upstream) */
void	fork_exec(t_cmd cmd, void (*bin)(t_cmd));

void	signal_handler(t_req ord);
void	sh_exec(t_cmd cmd);

/* __________________________________  */

#endif
