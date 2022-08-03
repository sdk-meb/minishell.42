/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:51 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/03 14:12:13 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   my command-line interface   */
#ifndef MYCLI_H 
# define MYCLI_H

/*
        __E-X-E-C-U-T-I-O-N____L_I_B_R_A_R_Y_  belongs __MINISHELL__
*/

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <dirent.h>

# include "types__.h"


extern  t_env env;
extern  _head av;

#ifdef __linux__  
#   include <linux/limits.h>
# define sys_nerr 107
#elif __APPLE__
#   include <sys/syslimits.h>
#endif  /*  FILENAME_MAX and PATH_MAX include define */






/* ************************* Shell builtin commands ************************* */
t_path      pwd(void);/*    get pathname of current working directory */
void        cd(t_path);/*      change the current working directory */
void        b_exit(_head shlvl, int obtn);
void        echo(_str put, bool line_opt);

void        exuc(t_path p_file);/* transforms the calling process into a new process /> subroutine */

void        ft_err(_str err_msg, t_req);/*     handel errors message \> perror , strerror*/

t_path      linking(t_path, t_req);/* track linking files */

# endif