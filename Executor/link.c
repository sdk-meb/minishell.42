/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:20:31 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/02 12:39:13 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "../lib/shell.h"

typedef struct s_linker{
    t_path  orgpath;/ * original file path or original location * /
    t_path  altpath;/ * alternative path linker * /
    t_path  difpath;
    int     _diff[2];

    struct s_linker *trk;
} t_linker;

void    diff(t_linker   *ln)
{
    t_path org;
    t_path alt;

    if (!(ln && ln->altpath && ln->orgpath))
        return ;
    org = ln->orgpath;
    alt = ln->altpath;
    while (*org && *alt && *org == *alt)
    {
        alt++;
        org++;
        
    }
    / * ... * /
}

t_path    linking(t_path path, t_req req)
{
    t_linker        *go;
    static t_linker **files;
    static int       linker;

    if (req == _GET)
    {
        if (linker && *(files))
            return ((*files)->altpath);
        return (NULL);
    }
    go = (t_linker *) malloc(go);
    go->orgpath = pwd();
    go->altpath = path;
    go->trk = NULL;
    if (linker)
        go->trk = *files;
    *files = go;
    return (NULL);
}
*/