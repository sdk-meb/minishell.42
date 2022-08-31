/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Built_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:32 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/31 16:52:00 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	echo(t_cmd cmd)
{
	int	new_line;
	int	i[2];

	new_line = true;
	i[0] = 0;
	while (cmd->arv[++i[0]] && cmd->arv[i[0]][0] == '-')
	{
		i[1] = 1;
		while (cmd->arv[i[0]][i[1]] == 'n')
			i[1]++;
		if (cmd->arv[i[0]][i[1]] || i[1] == 1)
			break ;
		new_line = false;
	}
	while (cmd->arv[i[0]])
	{
		write(cmd->out, cmd->arv[i[0]], ft_strlen(cmd->arv[i[0]]));
		if (cmd->arv[++i[0]])
			write(cmd->out, " ", 1);
	}
	if (new_line)
		write(cmd->out, "\n", 1);
	close_fd(cmd->in, cmd->out);
}

static void	b_exit(t_cmd cmd)
{
	int	i;

	i = 0;
	while (cmd->arc > 2 && ft_isdigit(cmd->arv[1][i]) == SUCCESS)
	{
		if (cmd->arv[1][++i] == '\0')
			return (stat_loc(1), ft_err("msh: exit: too many arguments", 109));
	}
	if (cmd->arc > 2)
	{
		ft_err("msh: exit: numeric argument required", 109);
		exit(255);
	}
	if (cmd->arc == 1)
		exit(0);
	exit (ft_atoi(cmd->arv[cmd->arc - 1]));
}

static void	pwd(t_cmd cmd)
{
	char	*pathname;

	if (cmd->arv[1] && cmd->arv[1][0] == '-' && (cmd->arv[1][1]
			|| (cmd->arv[1][1] == '-' && cmd->arv[1][2])))
	{
		close_fd(cmd->in, cmd->out);
		return (ft_err("pwd: invalid option\n", 109));
	}
	pathname = (char *)ft_calloc(PATH_MAX, 1);
	getcwd(pathname, PATH_MAX);
	write(cmd->out, pathname, ft_strlen(pathname));
	write(cmd->out, "\n", 1);
	close_fd(cmd->in, cmd->out);
	cmd->out = 1;
	cmd->in = 0;
}

static void	cd(t_cmd cmd)
{
	errno = 0;
	chdir(cmd->arv[1]);
	if (errno == SUCCESS)
	{
		set_env(ft_strjoin("OLDPWD=", get_env("PWD")));
		getcwd(get_env("PWD"), PATH_MAX);
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
		return (echo(cmd), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "cd", 3) == SUCCESS)
		return (cd(cmd), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "pwd", 4) == SUCCESS)
		return (pwd(cmd), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "env", 4) == SUCCESS)
		return (env(cmd), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "unset", 4) == SUCCESS)
		return (unset(cmd), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "exit", 5) == SUCCESS)
		return (b_exit(cmd), SUCCESS);
	if (ft_memcmp(mngr->arv[0], "export", 7) == SUCCESS)
		return (export(cmd), SUCCESS);
	return (FAILURE);
}
