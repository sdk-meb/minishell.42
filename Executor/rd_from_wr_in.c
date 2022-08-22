/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_from_wr_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:38:16 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/22 01:21:44 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	hd_out_of(t_cmd cmd)
{
	t_cmd	mngr;
	int		fd[2];

	mngr = cmd;
	if (mngr->cm->fds[STDIN_FILENO] != STDIN_FILENO)
		close(mngr->cm->fds[STDIN_FILENO]);
	pipe(fd);
	ft_err(NULL);
	mngr->cm->fds[STDIN_FILENO] = fd[STDIN_FILENO];
	write(fd[STDOUT_FILENO], mngr->token, sizeof(mngr->token));
	close(mngr->cm->fds[STDOUT_FILENO]);
	ft_err(NULL);
	cmd = cmd->next;
	cmd->type = 'H';
}

static void	rd_out_of(t_cmd cmd)
{
	t_cmd	mngr;

	mngr = cmd->next;
	if (mngr->cm->fds[STDIN_FILENO] != STDIN_FILENO)
		close(mngr->cm->fds[STDIN_FILENO]);
	mngr->cm->fds[STDIN_FILENO] = open(mngr->token, O_RDONLY);
	ft_err(mngr->token);
	cmd = cmd->next;
	cmd->type = 'F';
}

static void	insert_doc(t_cmd cmd)
{
	t_cmd	mngr;

	mngr = cmd->next;
	if (mngr->cm->fds[STDOUT_FILENO] != STDOUT_FILENO)
		close(mngr->cm->fds[STDOUT_FILENO]);
	mngr->cm->fds[STDOUT_FILENO] = open(mngr->token, O_WRONLY |
			O_CREAT | O_APPEND, 0744);
	cmd = cmd->next;
	cmd->type = 'F';
}

static void	insert_file(t_cmd cmd)
{
	t_cmd	mngr;

	mngr = cmd->next;
	if (mngr->cm->fds[STDOUT_FILENO] != STDOUT_FILENO)
		close(mngr->cm->fds[STDOUT_FILENO]);
	mngr->cm->fds[STDOUT_FILENO] = open(mngr->token, O_WRONLY |
			O_CREAT | O_ACCMODE, 0744);
	ft_err(mngr->token);
	cmd = cmd->next;
	cmd->type = 'F';
}

void	rf_wi(t_cmd cmd)
{
	t_cmd	mngr;

	mngr = cmd;
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
			cmd->cm->arc++;
		mngr = mngr->next;
	}
}
