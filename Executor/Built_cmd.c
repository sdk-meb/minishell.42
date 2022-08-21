/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Built_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:32 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/21 12:44:57 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	echo(t_cmd cmd)
{
	int	new_line;
	int	i;

	new_line = true;
	i = 0;
	while (cmd->arv[++i])
	{
		if (ft_memcmp(cmd->arv[i], "-n", 3) == SUCCESS)
			new_line = false;
		else
			write(cmd->fd[STDOUT_FILENO], cmd->arv[i], ft_strlen(cmd->arv[i]));
	}
	if (new_line)
		write(cmd->fd[STDOUT_FILENO], "\n", 1);
	if (cmd->fd[STDOUT_FILENO] != 1)
		close(cmd->fd[STDOUT_FILENO]);
	cmd->fd[STDOUT_FILENO] = -1;
}

static void	pwd(t_cmd cmd)
{
	char	*pathname;

	pathname = (char *)new_heap(PATH_MAX, TEMPORARY, 1);
	getcwd(pathname, PATH_MAX);
	write(cmd->fd[STDOUT_FILENO], pathname, ft_strlen(pathname));
	if (cmd->fd[STDOUT_FILENO] != 1)
		close(cmd->fd[STDOUT_FILENO]);
	cmd->fd[STDOUT_FILENO] = -1;
}

static void	cd(t_cmd cmd)
{
	chdir(cmd->arv[1]);
	if (errno)
		ft_err(cmd->arv[1], ERRMSG);
}

bool	bult_c(t_cmd cmd)
{
	t_cmd	mngr;

	mngr = cmd;
	if (!mngr)
		return (FAILURE);
	if (ft_memcmp(mngr->arv[0], "echo", 5) == SUCCESS)
		return (echo(cmd), SUCCESS);
	else if (ft_memcmp(mngr->arv[0], "cd", 3) == SUCCESS)
		return (cd(cmd), SUCCESS);
	else if (ft_memcmp(mngr->arv[0], "pwd", 4) == SUCCESS)
		return (pwd(cmd), SUCCESS);
	else if (ft_memcmp(mngr->arv[0], "env", 4) == SUCCESS)
		return (env(cmd), SUCCESS);
	else if (ft_memcmp(mngr->arv[0], "unset", 4) == SUCCESS)
		return (unset(cmd), SUCCESS);
	else if (ft_memcmp(mngr->arv[0], "export", 4) == SUCCESS)
		return (export(cmd), SUCCESS);
	return (FAILURE);
}
