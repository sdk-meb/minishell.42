/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Built_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:32 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/23 09:00:59 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	echo(t_cmd cmd)
{
	int	new_line;
	int	i;

	new_line = true;
	i = 0;
	if (ft_memcmp(cmd->arv[1], "-n", 3) == SUCCESS)
	{
		i = 1;
		new_line = false;
	}
	while (cmd->arv[++i])
	{
		write(cmd->out, cmd->arv[i],
			ft_strlen(cmd->arv[i]));
		write(cmd->out, " ", 1);
	}
	if (new_line)
		write(cmd->out, "\n", 1);
	if (cmd->out != 1)
		close(cmd->out);
	cmd->out = 1;
}

static void	pwd(t_cmd cmd)
{
	char	*pathname;

	pathname = (char *)ft_calloc(PATH_MAX, 1);
	getcwd(pathname, PATH_MAX);
	write(cmd->out, pathname, ft_strlen(pathname));
	write(cmd->out, "\n", 1);
	if (cmd->out != 1)
		close(cmd->out);
	cmd->out = 1;
}

static void	cd(t_cmd cmd)
{
	errno = 0;
	chdir(cmd->arv[1]);
	ft_err(cmd->arv[1], errno);
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
	{
		if (mngr->arc == 2)
			exit (ft_atoi(mngr->arv[1]));
		return (ft_err("msh: exit: too many arguments", 0), SUCCESS);
	}
	if (ft_memcmp(mngr->arv[0], "export", 7) == SUCCESS)
		return (export(cmd), SUCCESS);
	return (FAILURE);
}
