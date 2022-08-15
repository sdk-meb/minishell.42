/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:51 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/15 15:35:41 by mes-sadk         ###   ########.fr       */
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
/* __________________________________  */

#ifdef __linux__  
#   include <linux/limits.h>
# define sys_nerr 107
#elif __APPLE__
#   include <sys/syslimits.h>
#endif  /*  FILENAME_MAX and PATH_MAX include define */

/* __________________________________  */

# define APPROVED  0b0001000/* memory approved by programme */
# define TEMPORARY 0b0010000/* temporary memory */

typedef struct s_heap
{
        void *dng_ptr;/* dangling pointer *//*  {dangle : hold something so that it hangs loosely} */
        struct s_heap *extra;
        struct s_heap *prev;
}                        t_heap;/* garbage collector */

/* __________________________________  */

void ft_err(t_str, t_req);

void signal_handler();
void sh_exece(t_cmd*);
void    *new_heap(size_t, t_req);
void    c_delete(t_req);

/* __________________________________  */

# endif