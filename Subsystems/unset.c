/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:32:08 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/23 21:38:41 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	env(t_cmd cmd)
{
	t_envv	**env;
	t_envv	*envv;

	env = my_env(NULL, _GET);
	envv = *env;
	while (envv)
	{
		write(cmd->out, envv->name, ft_strlen(envv->name));
		write(cmd->out, "=", 2);
		write(cmd->out, envv->content, ft_strlen(envv->content));
		write(cmd->out, "\n", 2);
		envv = envv->next;
	}
	close_fd(cmd->in, cmd->out);
	cmd->out = 1;
	cmd->in = 0;
}

static void	unset_envv(t_str var)
{
	t_envv	**env;
	t_envv	*envv;
	t_envv	*prev;

	env = my_env(NULL, _GET);
	envv = *env;
	prev = *env;
	while (envv)
	{
		if (ft_strncmp(envv->name, var, INT32_MAX) == SUCCESS)
		{
			free((void *)envv->content);
			free((void *)envv->name);
			prev->next = envv->next;
			if (*env == envv)
				(*env) = prev;
			return (free((void *)envv));
		}
		prev = envv;
		envv = envv->next;
	}
	ft_err("unset: invalid parameter name", 109);
}

void	unset(t_cmd cmd)
{
	int	i;

	i = 0;
	if (!cmd->arv[1] || cmd->arv[i][0] == '$'
			|| cmd->arv[i][0] == '\'' || cmd->arv[i][0] == '\"')
		return (ft_err("unset: not enough arguments", 109));
	while (cmd->arv[++i])
	{
		unset_envv(cmd->arv[i]);
	}
	close_fd(cmd->in, cmd->out);
	cmd->out = 1;
	cmd->in = 0;
}
