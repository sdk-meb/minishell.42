/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Built_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:32 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/15 01:37:40 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	b_exit(t_cmd cmd)
{
	int	i;

	i = 0;
	while (cmd->arc > 2)
	{
		if (ft_isdigit(cmd->arv[1][i]))
			break ;
		if (cmd->arv[1][++i] == '\0')
			return (stat_loc(1), ft_err("M-sh: exit: too many arguments", 109));
	}
	glb_sig(RL_STATE_READCMD);
	if (cmd->arc > 2)
	{
		ft_err("M-sh: exit: numeric argument required", 109);
		ft_exit(255);
	}
	if (cmd->arc == 2)
		ft_exit(ft_atoi(cmd->arv[cmd->arc - 1]));
	ft_exit(stat_loc(EMPTY));
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
		pathname = current_path(NULL);
	write(cmd->out, pathname, ft_strlen(pathname));
	write(cmd->out, "\n", 1);
	close_fd(&(cmd->in), &(cmd->out));
	ft_exit (0);
}

static void	cd(t_cmd cmd)
{
	t_path		path;

	if (!cmd->arv[1])
		cmd->arv[1] = get_env("HOME");
	chdir(cmd->arv[1]);
	if (errno == SUCCESS)
	{
		set_env(ft_strjoin("OLDPWD=", get_env("PWD")));
		path = getcwd(NULL, OPEN_MAX);
		if (!path || !*path)
		{
			path = ft_strjoin(current_path(NULL), "/");
			set_env(ft_strjoin("PWD=", ft_strjoin(path, cmd->arv[1])));
			current_path(get_env("PWD"));
			errno = ENOENT;
		}
		else
			return (set_env(ft_strjoin("PWD=", path)), \
			current_path(get_env("PWD")), stat_loc(0), free((void *) path));
	}
	ft_err(cmd->arv[1], errno);
	stat_loc(1);
}

bool	bult_c1(t_cmd cmd)
{
	t_cmd	mngr;

	mngr = cmd;
	if (ft_memcmp(mngr->arv[0], "cd", 3) == SUCCESS)
		return (fork_exec(cmd, cd), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "unset", 4) == SUCCESS)
		return (fork_exec(cmd, unset), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "export", 7) == SUCCESS)
		return (fork_exec(cmd, export), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "exit", 5) == SUCCESS)
		return (fork_exec(cmd, b_exit), SUCCESS);
	return (FAILURE);
}

bool	bult_c(t_cmd cmd, bool ppe)
{
	t_cmd	mngr;

	mngr = cmd;
	errno = 0;
	if (ft_memcmp(mngr->arv[0], "echo", 5) == SUCCESS)
		return (fork_exec(cmd, echo), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "pwd", 4) == SUCCESS)
		return (fork_exec(cmd, pwd), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "env", 4) == SUCCESS)
		return (fork_exec(cmd, env), SUCCESS);
	if (ppe || glb_sig(EMPTY) == EOWNERDEAD
		|| glb_sig(EMPTY) == RL_STATE_READCMD)
		return (bult_c1(cmd));
	if (ft_memcmp(mngr->arv[0], "cd", 3) == SUCCESS)
		return (cd(cmd), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "unset", 4) == SUCCESS)
		return (unset(cmd), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "exit", 5) == SUCCESS)
		return (b_exit(cmd), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "export", 7) == SUCCESS)
		return (export(cmd), SUCCESS);
	return (FAILURE);
}
