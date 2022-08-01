/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 07:36:20 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/01 09:24:12 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <head.h>

void ft_err(_str err_msg, t_req msg)
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

void    fix_cderr(t_path   path)
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