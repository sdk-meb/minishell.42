/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:45:59 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/13 01:24:32 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	close_fd(int *from, int *to)
{
	if (from && *from != STDIN_FILENO)
	{
		close(*from);
		*from = STDIN_FILENO;
	}
	if (to && *to != STDOUT_FILENO)
	{
		close(*to);
		*to = STDOUT_FILENO;
	}
}

static void	cmd_pipe_cmd(t_cmd cmd)
{
	int		fds[2];

	close_fd(NULL, &(cmd->left->out));
	pipe(fds);
	cmd->left->out = fds[STDOUT_FILENO];
	cmd->left->pipe_not_used = fds[STDIN_FILENO];
	if (cmd->right->symbol == '|')
		cmd->right->left->in = fds[STDIN_FILENO];
	else
	{
		cmd->right->in = fds[STDIN_FILENO];
		cmd->right->pipe_not_used = fds[STDOUT_FILENO];
	}
}

void	pipe_x(t_cmd cmd)
{
	errno = 0;
	cmd_pipe_cmd(cmd);
}
