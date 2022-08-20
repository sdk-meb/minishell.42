/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:51 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/20 21:33:15 by mes-sadk         ###   ########.fr       */
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

# include <sys/types.h>
# include <sys/wait.h>

# include "minishell.h"
# include "../libft/mtypes.h"
/* __________________________________  */

#ifdef __linux__  
# include <linux/limits.h>
# define sys_nerr 107
# define PRIO_USER 2
#elif __APPLE__
# include <sys/syslimits.h>
#endif  /*  FILENAME_MAX and PATH_MAX include define */

/* __________________________________  */

# define HEREDOC	0x33/* << redirection */
# define APNDDOC	0x2E/* >> redirection  : append document */

/* __________________________________  */

void pipe_x(t_cmd fd_read, t_req ord);

void	ft_err(t_str str, t_req ord);

bool	bult_c(t_cmd cmd);

void	signal_handler();
void	sh_exec(t_cmd);

/* __________________________________  */

# endif