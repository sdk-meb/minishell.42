/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exuc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:41 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/22 01:49:15 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	cmd_path(t_cmd cmd)
{
	t_cmd	mngr;
	t_head	pathname;
	pid_t	i;

	errno = 0;
	mngr = cmd;
	while (mngr->type != 'w')
		mngr = mngr->next;
	pathname = (t_head)ft_split(_get_env("PATH"), ':');
	i = 0;
	while (pathname && pathname[++i] && errno)
	{
		pathname[i] = ft_strjoin(pathname[i], "/");
		pathname[i] = ft_strjoin(pathname[i], mngr->token);
		access(pathname[i], X_OK | F_OK);
		if (!errno)
			opendir(pathname[i]);
	}
	if (errno)
	{
		errno = 108;
		ft_err(ft_strjoin("msh: command not found: ", mngr->token));
	}
	else
		cmd->cm->arv[0] = pathname[i]; 
}

static void	plea_arguments_value(t_cmd cmd)
{
	t_cmd	mngr;
	int		ac;

	mngr = cmd;
	if (!mngr)
		return ;
	mngr->cm->arv = (char **) ft_calloc(sizeof(mngr->cm->arv) ,
			cmd->cm->arc + 1);
	ac = 0;
	cmd->cm->arv[cmd->cm->arc] = NULL;
	while (mngr && ac < cmd->cm->arc)
	{
		if (mngr->type == 'w')
			cmd->cm->arv[ac++] = mngr->token;
		mngr = mngr->next;
	}
}

static void	exec_bin(t_cmd cmd)
{
	printf("_________%s__11111________\n",cmd->cm->arv[0]);
	cmd_path(cmd);
	printf("_________%s____333333______\n",cmd->cm->arv[0]);
	execve(cmd->cm->arv[0], cmd->cm->arv, my_env(NULL, _GET));
}


static void	common_addr(t_cmd cmd)
{
	t_cmd	mn_cmd;
	t_cmd	mn_cmds;

	mn_cmds = cmd;
	while (mn_cmds)
	{
		mn_cmd = mn_cmds;
		if (mn_cmds->type == '|')
			mn_cmd = mn_cmds->left;
		mn_cmds->cm = (t_common_addr *) malloc(sizeof(mn_cmds->cm));
		while (mn_cmd)
		{
			mn_cmd->cm = mn_cmds->cm;
			mn_cmd = mn_cmd->next;
		}
		mn_cmds->cm->fds[STDIN_FILENO] = STDIN_FILENO;
		mn_cmds->cm->fds[STDOUT_FILENO] = STDOUT_FILENO;
		mn_cmds->cm->arv = NULL;
		mn_cmds->cm->arc = 0;
		mn_cmds->cm->err = 0;
		mn_cmds = cmd->right;
	}
}

void	sh_exec(t_cmd cmd)
{
	if (!cmd)
		return ;
	if (!cmd->cm)
		common_addr(cmd);
	if (cmd->type == '|')
	{
		pipe_x (cmd);
		rf_wi(cmd->left);
		plea_arguments_value(cmd->left);
		if (bult_c(cmd->left))
			fork_exec(cmd->left, exec_bin);
		return (sh_exec(cmd->right));
	}
	rf_wi(cmd);
	plea_arguments_value(cmd);
	if (bult_c(cmd))
		fork_exec(cmd, exec_bin);
}
