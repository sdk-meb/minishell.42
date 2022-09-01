/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:45:59 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/30 08:16:17 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	close_fd(int from, int to)
{
	if (from != STDIN_FILENO)
		close(from);
	if (to != STDOUT_FILENO)
		close(to);
}

static void	cmd_pipe_cmd(t_cmd cmd)
{
	int		fds[2];

	close_fd(STDIN_FILENO, cmd->left->out);
	cmd->left->out = STDOUT_FILENO;
	pipe(fds);
	cmd->left->out = fds[STDOUT_FILENO];
	if (cmd->right->symbol == '|')
		cmd->right->left->in = fds[STDIN_FILENO];
	else
		cmd->right->in = fds[STDIN_FILENO];
}

void	pipe_x(t_cmd cmd)
{
	errno = 0;
	cmd_pipe_cmd(cmd);
}
