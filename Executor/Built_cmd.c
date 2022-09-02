/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Built_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:32 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/02 16:25:55 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	b_exit(t_cmd cmd)
{
	int	i;

	i = 0;
	while (cmd->arc > 2 && ft_isdigit(cmd->arv[1][i]) == SUCCESS)
	{
		if (cmd->arv[1][++i] == '\0')
			return (stat_loc(1), ft_err("M-sh: exit: too many arguments", 109));
	}
	if (cmd->arc > 2)
	{
		ft_err("M-sh: exit: numeric argument required", 109);
		ft_exit(255, RUSAGE_CHILDREN + 1);
	}
	if (cmd->arc == 2)
		ft_exit(ft_atoi(cmd->arv[cmd->arc - 1]), RUSAGE_CHILDREN + 1);
	ft_exit(0, RUSAGE_CHILDREN + 1);
}

static void	pwd(t_cmd cmd)
{
	char	*pathname;

	if (cmd->arv[1] && cmd->arv[1][0] == '-' && (cmd->arv[1][1]
			|| (cmd->arv[1][1] == '-' && cmd->arv[1][2])))
	{
		close_fd(&(cmd->in), &(cmd->out));
		ft_err("pwd: invalid option", 109);
		exit (1);
	}
	pathname = getcwd(NULL, PATH_MAX);
	write(cmd->out, pathname, ft_strlen(pathname));
	write(cmd->out, "\n", 1);
	free(pathname);
	close_fd(&(cmd->in), &(cmd->out));
	exit (0);
}

static void	cd(t_cmd cmd)
{
	errno = 0;
	close_fd(&(cmd->in), &(cmd->out));
	chdir(cmd->arv[1]);
	if (errno == SUCCESS)
	{
		stat_loc(0);
		set_env(ft_strjoin("OLDPWD=", get_env("PWD")));
		getcwd(get_env("PWD"), PATH_MAX);/* !!?  leaks */
		return ;
	}
	ft_err(cmd->arv[1], errno);
	stat_loc(1);
}

bool	bult_c(t_cmd cmd)
{
	t_cmd	mngr;

	mngr = cmd;
	if (ft_memcmp(mngr->arv[0], "echo", 5) == SUCCESS)
		return (fork_exec(cmd, echo), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "cd", 3) == SUCCESS)
		return (cd(cmd), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "pwd", 4) == SUCCESS)
		return (fork_exec(cmd, pwd), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "env", 4) == SUCCESS)
		return (fork_exec(cmd, env), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "unset", 4) == SUCCESS)
		return (unset(cmd), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "exit", 5) == SUCCESS)
		return (b_exit(cmd), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "export", 7) == SUCCESS)
		return (export(cmd), SUCCESS);
	return (FAILURE);
}
