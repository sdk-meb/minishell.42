/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exuc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:41 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/07/31 15:30:49 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <head.h>

void ft_err(void *err_msg, bool msg)
{
    if (errno <= 0 || errno >= sys_nerr) /*  Known errors (errno) : sys_nerr 0 -> 106 */
        return ;
    if (msg == ERRMSG)
    {
        perror(err_msg); /* <err_msg>: Undefined error: 0 */
    }
    else
    {
        printf("%s\n", strerror(errno));
    }
}

void    fix_cderr(char *path)
{
    if (errno == EACCES)
        ft_err(ft_strjoin("msh$ cd", path), ERRMSG); /* leak !!!!!!!!! */
    else if (errno == EFAULT)
        ft_err("", ERRMSG);
    else if (errno == EIO)
        ft_err("", ERRMSG);
    else if (errno == ELOOP)
        ft_err("", ERRMSG);
    else if (errno == ENAMETOOLONG)
        ft_err("", ERRMSG);
    else if (errno == ENOENT)
        ft_err("", ERRMSG);
    else if (errno == ENOTDIR)
        ft_err("", ERRMSG);
}