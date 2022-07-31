

#ifndef MYCLI_H /* my command-line interface */
# define MYCLI_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <dirent.h>
# include <libft.h>
# include "../libft/libft.h"
//#include "minishell.h"

typedef char*  t_path;

#ifdef __linux__  
#   include <linux/limits.h>
#elif __APPLE__
#   include <sys/syslimits.h>
#endif  /*  FILENAME_MAX and PATH_MAX include define */

# define ERRMSG 0 /* add message to error name   */
# define STRERR 1 /* sufficiency with error name */

# define ITSELF   0
# define HARDLINK 1


typedef struct s_linker{
    t_path orgpath;/* original file path or original location */
    t_path altpath;/* alternative path linker */

    struct  s_linker on;
} t_linker;

char    *pwd(void);/*    get pathname of current working directory */
t_path    linked(t_path path, bool f_ree);
void    cd(char *path);/*      change the current working directory */
void    fix_cderr(char *path); /* fix chdir errors */
void    ft_err(void *err_msg, bool);/*     handel errors message \> perror , strerror*/

# endif