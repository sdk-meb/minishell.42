/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:34:19 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/03 09:39:14 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../lib/shell.h"

void    ensure_env(t_env env)
{
    save_exp(env);
}

t_index    varname_rlz(_str var)
{
    t_index cas_e;
    
    if (!var || !*var)
        return (EXIT_FAILURE);
    cas_e = 0;
    while (var[cas_e])
    {
        cas_e++;/* !!!!!!!!!!!!!!!!!  */
    }
    return (cas_e);
}

t_env    ft_env(t_av    arg)
{
    t_var   **envv;
    t_index i;
    
    i = 0;
    if (arg)
        printf("%s", getenv(*arg));
    else
    {
        envv = save_exp(NULL);
        if (!envv)
            return NULL;
        while ((*envv)->env[i])
            printf("%s\n",(*envv)->env[i++]);
    }
    return NULL;
}