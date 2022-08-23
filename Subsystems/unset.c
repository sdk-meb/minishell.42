/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:32:08 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/23 13:46:04 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"


void	*get_env(t_str var)
{
	t_env	**env;

	env = my_env(NULL, _GET);
	while ((*env)->next)
	{
		if (ft_strncmp((*env)->name, var, INT32_MAX) == SUCCESS)
			return ((void *)(*env)->content + 1);
		(*env) = (*env)->next;
	}
	return ("");
}

void	env(t_cmd cmd)
{
	t_env	**env;

	(void)cmd;
	env = my_env(NULL, _GET);
	while ((*env)->next)
	{
		write(cmd->out, (*env)->name, ft_strlen((*env)->name));
		write(cmd->out, "=", 2);
		write(cmd->out, (*env)->content, ft_strlen((*env)->content));
		write(cmd->out, "\n", 2);
		(*env) = (*env)->next;
	}
	if (cmd->out != STDOUT_FILENO)
		close(cmd->out);
	if (cmd->in != STDIN_FILENO)
		close(cmd->in);
}

static void	unset_env(t_str var)
{
	t_env	**env;
	t_env	*temp;

	env = my_env(NULL, _GET);
	temp = *env;
	while (*env)
	{
		if (ft_memcmp(temp->name, var, INT32_MAX) == SUCCESS)
		{
			free((void *)(*env)->content);
			free((void *)(*env)->name);
			(*env) = temp->next;
			if (temp == (*env))
				my_env(env, SAVE);
			return (free((void *)temp));
		}
		(*env) = temp;
		temp = temp->next;
	}
	ft_err("unset: invalid parameter name", 0);
}

void	unset(t_cmd cmd)
{
	int	i;

	i = 0;
	if (!cmd->arv[1] || cmd->arv[i][0] == '$'
			|| cmd->arv[i][0] == '\'' || cmd->arv[i][0] == '\"')
		return (ft_err("unset: not enough arguments", 0));
	while (cmd->arv[++i])
	{
		unset_env(cmd->arv[i]);
	}
	if (cmd->out != STDOUT_FILENO)
		close(cmd->out);
	if (cmd->in != STDIN_FILENO)
		close(cmd->in);
}
