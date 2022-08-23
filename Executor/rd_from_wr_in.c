/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_from_wr_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:38:16 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/23 03:04:24 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	hd_out_of(t_cmd mngr, t_cmd cmd)
{
	int		fd[2];

	if (cmd->in != STDIN_FILENO)
		close(cmd->in);
	pipe(fd);
	cmd->in = fd[STDIN_FILENO];
	write(fd[STDOUT_FILENO], mngr->token, sizeof(mngr->token));
	close(cmd->out);
	ft_err(NULL, errno);
}

static void	rd_out_of(t_cmd mngr, t_cmd cmd)
{
	if (cmd->in != STDIN_FILENO)
		close(cmd->in);
	cmd->in = open(mngr->token, O_RDONLY);
	ft_err(mngr->token, errno);
	cmd->type = 'F';
}

static void	insert_doc(t_cmd mngr, t_cmd cmd)
{
	if (cmd->out != STDOUT_FILENO)
		close(cmd->out);
	cmd->out = open(mngr->token, O_WRONLY |
			O_CREAT | O_APPEND, 0644);
	cmd->type = 'F';
}

static void	insert_file(t_cmd mngr, t_cmd cmd)
{
	if (cmd->out != STDOUT_FILENO)
		close(cmd->out);
	cmd->out = open(mngr->token, O_WRONLY |
			O_TRUNC | O_CREAT, 0644);
	mngr->type = 'F';
}

void	rf_wi(t_cmd cmd)
{
	t_cmd	mngr;

	mngr = cmd;
	cmd->arc = 0;
	while (mngr)
	{
		if (mngr->type == HEREDOC)
			hd_out_of(mngr, cmd);
		else if (mngr->type == '<')
			rd_out_of(mngr->next, cmd);
		else if (mngr->type == O_APPEND)
			insert_doc(mngr->next, cmd);
		else if (mngr->type == '>')
			insert_file(mngr->next, cmd);
		else if (mngr->type == 'w')
			cmd->arc++;
		mngr = mngr->next;
	}
}
