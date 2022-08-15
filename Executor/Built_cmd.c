/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Built_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:32 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/13 22:19:54 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Include/minishell.h"

void    echo(t_str put, bool line_opt)
{
    (void)put;
    line_opt = 1;    
}

void  pwd()/* leak */
{
    char*   pathname;

    pathname = (char *)malloc (PATH_MAX);
    getcwd(pathname, PATH_MAX);

}

void    cd(t_path   path)
{
    if (!path || !*path)
        return ;
    if (chdir(path))
        ft_err(ft_strdup(path), ERRMSG);
}

void    xport()
{
    return ;
}

void    env()
{
    return ;
}

void    unset()
{
    return ;
}
