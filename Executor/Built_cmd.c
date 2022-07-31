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

# include <head.h>

bool    linked()
{
    staic t_linker *files;
    static 
    files = (t_linker *)malloc (sizeof(files));


}

char    *pwd()
{
    char*   pathname;

    pathname = (char *)malloc (PATH_MAX);
    if (!getcwd(pathname, PATH_MAX))
        return (free(pathname), NULL);
    return (pathname);
}

void    cd(char *path)
{
    if (chdir(path))
        fix_cderr(path);
    if (ft_memcmp(pwd(), path))
        linking(path);
    
    printf("%s\n",pwd());  
}