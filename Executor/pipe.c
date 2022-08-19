/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:45:59 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/19 09:11:12 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void pipe_x(t_cmd c_fd, t_req ord)
{
	int fds[2];
	t_cmd fd_r;

	fd_r = c_fd->right;
	if (ord == _GET)
	{
		pipe(fds);
		(c_fd)->left->fd[STDOUT_FILENO] = fds[STDOUT_FILENO];
		if (fd_r->type == '|')
			fd_r = fd_r->left;
		(fd_r)->fd[STDIN_FILENO] = fds[STDIN_FILENO];
		return;
	}
	close(fds[STDIN_FILENO]);
	close(fds[STDOUT_FILENO]);
}
