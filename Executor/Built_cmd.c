/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Built_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:32 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/06 21:27:13 by mes-sadk         ###   ########.fr       */
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
		ft_exit(255);
	}
	if (cmd->arc == 2)
		ft_exit(ft_atoi(cmd->arv[cmd->arc - 1]));
	ft_exit(0);
}

static void	pwd(t_cmd cmd)
{
	char	*pathname;

	if (cmd->arv[1] && cmd->arv[1][0] == '-' && (cmd->arv[1][1]
			|| (cmd->arv[1][1] == '-' && cmd->arv[1][2])))
	{
		close_fd(&(cmd->in), &(cmd->out));
		ft_err("pwd: invalid option", 109);
		ft_exit (1);
	}
	pathname = getcwd(NULL, PATH_MAX);
	if (!pathname || !*pathname)
		pathname = get_env("PWD");
	write(cmd->out, pathname, ft_strlen(pathname));
	write(cmd->out, "\n", 1);
	close_fd(&(cmd->in), &(cmd->out));
	ft_exit (0);
}

static void	cd(t_cmd cmd)
{
	t_path		path;

	close_fd(&(cmd->in), &(cmd->out));
	errno = 0;
	chdir(cmd->arv[1]);
	if (errno == SUCCESS)
	{
		set_env(ft_strjoin("OLDPWD=", get_env("PWD")));
		path = getcwd(NULL, OPEN_MAX);
		if (!path || !*path)
		{
			path = ft_strjoin(get_env("PWD"), "/");
			path = ft_strjoin(path, cmd->arv[1]);
			set_env(ft_strjoin("PWD=", ft_strjoin(path, cmd->arv[1])));
			ft_err("", ENOENT);
		}
		else
			getcwd(get_env("PWD"), OPEN_MAX);
		stat_loc(0);
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
