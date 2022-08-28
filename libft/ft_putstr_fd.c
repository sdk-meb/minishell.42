/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:16:58 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/27 21:49:22 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
	{
		write(fd, "(null)", 7);	
		return ;
	}
	write(fd, str, ft_strlen(str));
}
