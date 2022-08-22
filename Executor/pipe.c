/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:45:59 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/22 10:51:50 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	cmd_pipe_cmd(t_cmd c_fd)
{
	int		fds[2];
	t_cmd	fd_r;

	fd_r = c_fd->right;
	if (c_fd->cm->fds[STDOUT_FILENO] != STDOUT_FILENO)
		close(c_fd->cm->fds[STDOUT_FILENO]);
	pipe(fds);
	ft_err(NULL, errno);
	(c_fd)->left->cm->fds[STDOUT_FILENO] = fds[STDOUT_FILENO];
	if (fd_r->type == '|')
		fd_r = fd_r->left;
	ft_err(NULL, errno);
	(fd_r)->cm->fds[STDIN_FILENO] = fds[STDIN_FILENO];
}

void	pipe_x(t_cmd c_fd)
{
	errno = 0;
	cmd_pipe_cmd(c_fd);
}
