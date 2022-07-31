/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Built_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:32 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/07/31 15:30:42 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../lib/head.h"
# include <head.h>

t_path    linked(t_path path)
{
    t_linker        *go;
    static t_linker **files;
    static int       linker;

    if (!path)
    {
        if (linker && *(files))
            return (*(files)->altpath);
        return (NULL);
    }
    go= (t_linker *) malloc(files *);
    go->orgpath = pwd();
    go->altpath = path;
    go->on = NULL;
    if (linker)
        go->on = *files;
    *files = go;
    return (NULL);
}

char    *pwd()
{
    char*   pathname;

    pathneme = linked(NULL);
    if (pathname)
        return (pathname);
    pathname = (char *)malloc (PATH_MAX);
    if (!getcwd(pathname, PATH_MAX))
        return (free(pathname), NULL);
    return (pathname);
}

void    cd(char *path)
{
    if (ft_memcpm(path, "../", 3) && linked(NULL))
    {
        if (chdir(path))
            fix_cderr(path);
        if (ft_memcmp(pwd(), path))
            linking(path);
    }
    printf("%s\n",pwd());  
}
