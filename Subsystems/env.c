/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:34:19 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/02 16:11:11 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../lib/shell.h"

_ptr    get_var(t_env env, _str var)
{
    t_index   tabl;
    t_index   cas_e;
    _ptr    get;
    
    if (!var || !*var)
        return ((void *)EXIT_FAILURE);
    cas_e = (t_index) ft_strlen(var);
    tabl = 0;
    while (env[tabl] && ft_memcmp(env[tabl], var, cas_e + 1))
        tabl++;
    if (!env[tabl])
        return ((void *)EXIT_FAILURE);
    get = env[tabl];
    return (get + cas_e + 1);
}

void    set_var(_str name, _str val)
{
    
}


t_index    varname_rlz(_str var)
{
    t_index cas_e;
    
    if (!var || !*var)
        return (EXIT_FAILURE);
    cas_e = 0;
    while (var[cas_e])
    {
        cas_e++;
    }
    return (cas_e);
}