/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:34:19 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/20 15:16:13 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Include/minishell.h"

char  **my_env(char **env, t_req ord)
{
    static char **envr;

    if (ord == SAVE)
        envr = env;
    env = envr;
    return(env);    
}

void    *_get_env(t_str var)
{
    char **env;
    int     i;
    size_t   len;

    i = 0;
    len = ft_strlen(var);
    env = my_env(NULL, _GET);
    while (env[i])
    {
        while (env[i] && ft_memcmp(env[i], var, len))
            i++;
        if (env[i] && ft_memcmp(ft_substr(env[i], len, 1), "=", len))
            break;        
    }
    if (!env[i])
        return (NULL);
    return (ft_substr(env[i], len + 1, ft_strlen(env[i]) - len));
}

void    env()
{
    int i;
    char **env;

    i = 0;
    env = my_env(NULL, _GET);
    while (env[i])
        printf("%s\n", env[i++]);
}

void   env_proc(char **env, t_str var,t_req ord)
{
    int i;
    char **_env;

    i = 0;
    _env = env;
    while (env[i])
        i++;
    if (ord == _ADD)
    {
        env = new_heap(sizeof(env) * (++i + 1), APPROVED, 1);
        env[i] = NULL;
        env[--i] = ft_strdup(var);
    }
    while (i--)
    {
        env[i] = ft_strdup(_env[i]);
        if (ord == _ADD)
            free(_env[i]);
    }
    my_env(env, SAVE);
}
