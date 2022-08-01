/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:51 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/01 12:16:49 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYCLI_H /* my command-line interface */
# define MYCLI_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <dirent.h>
# include <libft.h>

//#include "minishell.h"

typedef const char* t_path;/* path name and also considered as file name */
typedef const char* _str;
typedef char*       _ptr;
typedef char**      _head;

extern  _head env;
extern  _head av;

typedef const char  t_req;/*  work request */

#ifdef __linux__  
#   include <linux/limits.h>
# define sys_nerr 107
#elif __APPLE__
#   include <sys/syslimits.h>
#endif  /*  FILENAME_MAX and PATH_MAX include define */

/*   specific work request  */
# define ERRMSG 0 /* add message to error name   */
# define STRERR 1 /* sufficiency with error name */
# define _SAVE      0x00000
# define _RETURN    0x00000
# define _free      0x00000
# define _CHECK     0x00000
# define _ALT       0x00000
# define _ORG       0x00000
# define _SET       0x00000
# define _GET       0x00000


typedef struct s_linker{
    t_path  orgpath;/* original file path or original location */
    t_path  altpath;/* alternative path linker */
    t_path  difpath;
    int     _diff[2];

    struct s_linker *trk;
} t_linker;
/* ************************* Shell builtin commands ************************* */
t_path      pwd(void);/*    get pathname of current working directory */
void        cd(t_path);/*      change the current working directory */
void        b_exit(_head shlvl, int obtn);
void        echo(_str put, bool line_opt);

void        exuc(t_path p_file);/* transforms the calling process into a new process /> subroutine */

void        fix_cderr(t_path); /* fix chdir errors */
void        ft_err(_str err_msg, t_req);/*     handel errors message \> perror , strerror*/

t_path      linking(t_path, t_req);/* track linking files */
# endif