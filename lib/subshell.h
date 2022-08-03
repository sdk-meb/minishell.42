/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:19:52 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/03 01:32:23 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSYSTEM_H
# define SUBSYSTEM_H

#include "../lib/shell.h"

/*
    structure indicate the global shell variable
        from envirenment and exported 
*/
typedef struct s_var{
    _str name;
    _str val;

    t_env   env;
    struct s_var *nextvr;
} t_var;

/*  check existend of variable and/or get variable value */
t_env        ft_export(t_req); 
t_env        ft_env(t_av);
/*  varible names rules */
t_index     varname_rlz(_str);

/*  keep addr and return it  */
t_var**     save_exp(t_env);

/*  duplicate environment variables and save it by exported variables */
void        ensure_env(t_env);


# endif