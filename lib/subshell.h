/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:19:52 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/02 16:14:16 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSYSTEM_H
# define SUBSYSTEM_H

#include "../lib/shell.h"

typedef struct s_var{
    _str name;
    _str val;

    struct s_var *nextvr;
} t_var;

_ptr    get_var(t_env env, _str var);/* check existend of var and/or get variable value */
t_index    varname_rlz(_str var);/*       varible names rules*/

# endif