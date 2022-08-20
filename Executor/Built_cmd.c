/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Built_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:32 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/20 11:10:00 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	echo(int fd, t_str put, t_req n_line)
{
	write(fd, put, ft_strlen(put));
	if (n_line == '\n')
		write(fd, "\n", 1);
}

void	pwd(int fd)
{
	char	*pathname;

	pathname = (char *)new_heap(PATH_MAX, TEMPORARY, 1);
	getcwd(pathname, PATH_MAX);
	write(fd, pathname, ft_strlen(pathname));
	c_delete(TEMPORARY, 1);
}

void	cd(t_path path)
{
	if (!path || !*path)
		return ;
	if (chdir(path))
		ft_err(ft_strdup(path), ERRMSG);
}

bool	bult_c(t_cmd cmd)
{
	(void)cmd;
	return 0;
}