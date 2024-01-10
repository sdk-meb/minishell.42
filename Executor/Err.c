/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 07:36:20 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/03 11:29:41 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_err(t_str err_msg, int erno)
{
	errno = erno;
	if (erno == 127)
		stat_loc(erno);
	if (erno == SUCCESS)
		return ;
	if (errno > 0 && errno < 
	#ifdef sys_nerr /* sys_nerr:
           From glibc 2.19 to glibc 2.31:
               _DEFAULT_SOURCE
           glibc 2.19 and earlier:
               _BSD_SOURCE
	*/
		sys_nerr
	#else 
		__FLT64_MAX_EXP__
	#endif
	)
		perror(err_msg);
	else
	{
		write(2, err_msg, ft_strlen(err_msg));
		write(2, "\n", 1);
	}
	errno = 0;
}
