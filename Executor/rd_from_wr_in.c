/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_from_wr_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:38:16 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/24 01:06:12 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	hd_out_of(t_cmd mngr, t_cmd cmd)
{
	int		fd[2];

	close_fd(cmd->in, STDOUT_FILENO);
	pipe(fd);
	cmd->in = fd[STDIN_FILENO];
	write(fd[STDOUT_FILENO], mngr->token, sizeof(mngr->token));
	close(cmd->out);
	cmd->out = STDOUT_FILENO;
}

static void	rd_out_of(t_cmd mngr, t_cmd cmd)
{
	close_fd(cmd->in, STDOUT_FILENO);
	cmd->in = open(mngr->token, O_RDONLY);
	ft_err(mngr->token, errno);
	mngr->type = 'F';
}

static void	insert_doc(t_cmd mngr, t_cmd cmd)
{
	close_fd(STDIN_FILENO, cmd->out);
	cmd->out = open(mngr->token, O_WRONLY
			| O_CREAT | O_APPEND, 0644);
	ft_err(mngr->token, errno);
	mngr->type = 'F';
}

static void	insert_file(t_cmd mngr, t_cmd cmd)
{
	close_fd(STDIN_FILENO, cmd->out);
	cmd->out = open(mngr->token, O_WRONLY
			| O_TRUNC | O_CREAT, 0644);
	ft_err(mngr->token, errno);
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
