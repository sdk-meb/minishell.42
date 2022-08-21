/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:45:59 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/21 13:19:14 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	redirection_pipe(t_cmd c_fd)
{
	if (c_fd->fd[0])
		return ;
}

static void	cmd_pipe_cmd(t_cmd c_fd)
{
	int		fds[2];
	t_cmd	fd_r;

	fd_r = c_fd->right;
	pipe(fds);
	(c_fd)->left->fd[STDOUT_FILENO] = fds[STDOUT_FILENO];
	if (fd_r->type == '|')
		fd_r = fd_r->left;
	(fd_r)->fd[STDIN_FILENO] = fds[STDIN_FILENO];
	return ;
}

void	pipe_x(t_cmd c_fd, t_req ord)
{
	if (ord == '|')
		cmd_pipe_cmd(c_fd);
	else
		redirection_pipe(c_fd);
}
