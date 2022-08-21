/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exuc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:41 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/21 13:19:09 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static t_path	cmd_path(t_cmd cmd)
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

static t_head	plea_arguments_value(t_cmd cmd)
{
	t_cmd	mngr;
	t_head	av;
	int		ac;

	mngr = cmd;
	av = malloc(cmd->arc + 1);
	ac = 0;
	av[cmd->arc] = NULL;
	while (mngr && ac < cmd->arc)
	{
		if (mngr->type == CMIN)
			av[ac++] = mngr->token;
		mngr = mngr->next;
	}
	return (av);
}

static void	exec_bin(t_cmd cmd)
{
	execve(cmd_path(cmd), plea_arguments_value(cmd), my_env(NULL, _GET));
}

void	sh_exec(t_cmd cmd)
{
	if (!cmd)
		return ;
	if (cmd->type == '|')
	{
		pipe_x (cmd, _GET);
		rf_wi(cmd->left);
		if (bult_c(cmd->left))
			fork_exec(cmd->left, exec_bin);
		return (sh_exec(cmd->right));
	}
	rf_wi(cmd);
	if (bult_c(cmd))
		fork_exec(cmd->left, exec_bin);
}
