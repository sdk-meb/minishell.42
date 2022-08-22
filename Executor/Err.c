/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 07:36:20 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/22 10:01:41 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	ft_err(t_str err_msg, int erno)//int errno_)
{
	errno = erno;
	if (erno == SUCCESS)
		return ;
	if (errno > 0 && errno < sys_nerr)
		perror(err_msg);/*  Known errors (errno) : sys_nerr 0 -> 106 */
	else
	{
		write(2, err_msg, ft_strlen(err_msg));
		write(2, "\n", 1);
	}
	errno = 0;
}
