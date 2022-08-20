/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exuc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:41 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/20 22:44:06 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	exec_bin(t_path p_file, t_head arg)
{
	t_req	permit;
	t_head	pathname;
	pid_t	i;

	i = fork();
	if (i)
	{
		execve(p_file, (char *const *)arg, my_env(NULL, _GET));/* Overlay (programming) */
	}
	ft_err(p_file, ERRMSG);
}

static t_head plea_arguments_value(t_cmd cmd)
{
	t_cmd	mngr;
	t_head	av;
	int		ac;
	
	mngr = cmd;
	av = malloc(cmd->arg + 1);
	ac = 0;
	av[cmd->arg] = NULL;
	while (mngr && ac < cmd->arg)
	{
		if (mngr->type == CMIN)
			av[ac++] = mngr->token;
		mngr = mngr->next;
	}
	return (av);
}

static t_path cmd_path(t_cmd cmd)
{
	t_cmd	mngr;
	t_head	pathname;
	pid_t	i;

	mngr = cmd;
	while (mngr->type != CMIN)
		mngr = mngr->next;
	pathname = (t_head)ft_split(getenv("PATH"), ':');
	i = 0;
	while (pathname[i])
	{
		pathname[i] = ft_strjoin(pathname[i], "/");
		access(ft_strjoin(pathname[i++], mngr->token), X_OK | F_OK);
		if (!errno)
			break ;
	}
	if (errno)
		return (ft_err(mngr->token, ERRMSG), NULL);
	return (pathname[i]);
}

static void hd_out_of(t_cmd cmd)
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

static void  rd_out_of(t_cmd cmd)
{
	t_cmd	mngr;
	int		fd[2];

	mngr = cmd->next;
	close(mngr->fd[STDIN_FILENO]);
	mngr->fd[STDIN_FILENO] = open(mngr->token, O_RDONLY);
	cmd = cmd->next;
}

static void insert_doc(t_cmd cmd)
{
	t_cmd	mngr;

	mngr = cmd->next;
	close(mngr->fd[STDOUT_FILENO]);
	mngr->fd[STDOUT_FILENO] = open(mngr->token, O_WRONLY | O_CREAT | O_APPEND,\
	0744);
	cmd = cmd->next;
}

static void insert_file(t_cmd cmd)
{
	t_cmd	mngr;

	mngr = cmd->next;
	close(mngr->fd[STDOUT_FILENO]);
	mngr->fd[STDOUT_FILENO] = open(mngr->token, O_WRONLY | O_CREAT | O_ACCMODE,\
	0744);
	cmd = cmd->next;
}

static void	redirected(t_cmd cmd)
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

void sh_exec(t_cmd cmd)
{
	if (!cmd)
		return;
	if (cmd->type == '|')
	{
		pipe_x (cmd, _GET);
		redirected(cmd->left);
		mng_exec(cmd->left);
		// if (bult_c(cmd))
		// 	mng_exec(cmd);
		return (sh_exec(cmd->right));
	}
	redirected(cmd);
	// if (bult_c(cmd))
	// 	mng_exec(cmd);
}
