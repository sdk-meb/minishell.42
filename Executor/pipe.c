/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:45:59 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/23 02:36:04 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	cmd_pipe_cmd(t_cmd cmd)
{
	int		fds[2];

	if (cmd->left->out != STDOUT_FILENO)
		close(cmd->left->out);
	cmd->left->out = STDOUT_FILENO;
	pipe(fds);
	ft_err(NULL, errno);
	cmd->left->out = fds[STDOUT_FILENO];
	if (cmd->right->type == '|')
		cmd->right->left->in = fds[STDIN_FILENO];
	else
		cmd->right->in = fds[STDIN_FILENO];
}

void	pipe_x(t_cmd cmd)
{
	errno = 0;
	cmd_pipe_cmd(cmd);
}
