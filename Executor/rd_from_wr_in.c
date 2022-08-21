/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_from_wr_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:38:16 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/21 12:52:56 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	hd_out_of(t_cmd cmd)
{
	t_cmd	mngr;
	int		fd[2];

	mngr = cmd->next;
	close(mngr->fd[STDIN_FILENO]);
	pipe(fd);
	mngr->fd[STDIN_FILENO] = fd[STDIN_FILENO];
	write(fd[STDOUT_FILENO], mngr->token, sizeof(mngr->token));
	close(mngr->fd[STDIN_FILENO]);
	cmd = cmd->next;
}

static void	rd_out_of(t_cmd cmd)
{
	t_cmd	mngr;

	mngr = cmd->next;
	close(mngr->fd[STDIN_FILENO]);
	mngr->fd[STDIN_FILENO] = open(mngr->token, O_RDONLY);
	cmd = cmd->next;
}

static void	insert_doc(t_cmd cmd)
{
	t_cmd	mngr;

	mngr = cmd->next;
	close(mngr->fd[STDOUT_FILENO]);
	mngr->fd[STDOUT_FILENO] = open(mngr->token, O_WRONLY | O_CREAT | O_APPEND,
			0744);
	cmd = cmd->next;
}

static void	insert_file(t_cmd cmd)
{
	t_cmd	mngr;

	mngr = cmd->next;
	close(mngr->fd[STDOUT_FILENO]);
	mngr->fd[STDOUT_FILENO] = open(mngr->token, O_WRONLY | O_CREAT | O_ACCMODE,
			0744);
	cmd = cmd->next;
}

void	rf_wi(t_cmd cmd)
{
	t_cmd	mngr;

	mngr = cmd;
	pipe_x(cmd, 'R');
	while (mngr)
	{
		if (mngr->type == HEREDOC)
			hd_out_of(mngr);
		else if (mngr->type == '<')
			rd_out_of(mngr);
		else if (mngr->type == O_APPEND)
			insert_doc(mngr);
		else if (mngr->type == '>')
			insert_file(mngr);
		else
			mngr->type = CMIN;/* command and argument */
		mngr = mngr->next;
	}
}
