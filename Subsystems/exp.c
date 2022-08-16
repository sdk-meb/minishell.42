/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:26:42 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/16 23:53:53 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Include/minishell.h"

void    set_env(t_str var)
{
    char    **env;
    int     i;
    t_ptr   ptr;

    i = -1;
    env = my_env(NULL, _GET);
    while (env[++i])
    {
        ptr = ft_strchr(env[i], '=');
        if (ft_memcmp(env[i], ptr, ft_strlen(env[i]) - ft_strlen(ptr)))
        {
            free(env[i]);
            env[i] = ft_substr(var, 0, ft_strlen(var));
            return ; 
        } 
    }
    env_proc(env, var,_ADD);
}

void    ex_port()
{
    char    **env;
    int     i;
    t_ptr   ptr;

    i = -1;
    env = my_env(NULL, _GET);
    while (env[++i])
    {
        ptr = ft_strchr(env[i], '=');
        printf("declare -x %s\"%s\"\n",\
        ft_substr(env[i], 0, ft_strlen(env[i]) - ft_strlen(ptr)), ptr);
    }
}