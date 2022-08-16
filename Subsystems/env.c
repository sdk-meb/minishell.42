/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:34:19 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/16 23:53:13 by mes-sadk         ###   ########.fr       */
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
    return (ft_substr(env[i], len, ft_strlen(env[i]) - len));
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
    if (ord == _ADD)
    {
        while (env[i])
            i++;
        _env = malloc(sizeof(env) * (i + 1));
    }
    i = -1;
    while (env[++i])
    {
        _env[i] = ft_strdup(env[i]);
        if (ord == _ADD)
            free(env[i]);
    }
    if (ord == _ADD)
    {
        _env[i] = ft_strdup(var);
        _env[i + 1] = NULL;
        my_env(_env, SAVE);
        return ; 
    }
    my_env(env, SAVE);
}
