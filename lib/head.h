

#ifndef MYCLI_H /* my command-line interface */
# define MYCLI_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <dirent.h>
# include <libft.h>

//#include "minishell.h"

#ifdef __linux__  
#   include <linux/limits.h>
#elif __APPLE__
#   include <sys/syslimits.h>
#endif  /*  FILENAME_MAX and PATH_MAX include define */

# define ERRMSG 0 /* add message to error name   */
# define STRERR 1 /* sufficiency with error name */

typedef struct s_linker{
    const char *orig_path;/* original file path or original location */
    const char *alt_path;/* alternative path linker */

    struct      *s_linker;
} t_linker;

char    *pwd(void);/*    get pathname of current working directory */
void    cd(char *path);/*      change the current working directory */
void    fix_cderr(char *path); /* fix chdir errors */
void    ft_err(void *err_msg, bool);/*     handel errors message \> perror , strerror*/
# endif