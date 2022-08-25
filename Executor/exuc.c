/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exuc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:41 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/25 11:58:37 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	cmd_path(t_cmd cmd, t_head pathname)
{
	struct stat	buf;
	pid_t		i;

	i = errno;
	while (pathname && pathname[++i] && errno)
	{
		errno = 0;
		buf.st_mode = 0;
		pathname[i] = ft_strjoin(pathname[i], "/");
		pathname[i] = ft_strjoin(pathname[i], cmd->arv[0]);
		access(pathname[i], F_OK | X_OK);
		if (errno == SUCCESS)
			lstat(pathname[i], &buf);
		if (S_ISREG(buf.st_mode) == true)
			break ;
		errno = 1;
	}
	if (errno)
		ft_err(ft_strjoin("msh: command not found: ", cmd->arv[0]), 127);
	else
		cmd->arv[0] = pathname[i];
}

static void	plea_arguments_value(t_cmd cmd)
{
	t_cmd	mngr;
	char	*av;

	mngr = cmd;
	if (!mngr)
		return ;
	av = "";
	while (mngr)
	{
		if (mngr->type == 'w')
		{
			av = ft_strjoin(av, mngr->token);
			av = ft_strjoin(av, "\003");
		}
		mngr = mngr->next;
	}
	cmd->arv = (char **)ft_split(av, '\03');
}

static void	exec_bin(t_cmd cmd)
{
	char	*av[29];

	av[28] = NULL;
	errno = -1;

	if (ft_memcmp(cmd->arv[0], "./", 2) == SUCCESS || cmd->arv[0][0] == '/')
	{
		if (ft_memcmp(cmd->arv[0], "./", 2) == SUCCESS)
			ft_memmove((void *)cmd->arv[0], (void *)(cmd->arv[0] + 2)
				, ft_strlen(cmd->arv[0]) - 1);
		execve(cmd->arv[0], cmd->arv, av);
	}
	else
	{
		cmd_path(cmd, (t_head)ft_split(get_env("PATH"), ':'));
		execve(cmd->arv[0], cmd->arv, NULL);
	}
	if (ft_memcmp(cmd->arv[0], "./", 2) && cmd->arv[0][0] != '/')
		errno = 0;
}

void	sh_exec(t_cmd cmd)
{
	if (!cmd)
		return ;
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
