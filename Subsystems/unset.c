/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:32:08 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/31 19:51:38 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	unset_envv(t_str var)
{
	t_envv	**env;
	t_envv	*envv;
	t_envv	*prev;

	env = my_env(NULL, _GET);
	envv = *env;
	prev = *env;
	stat_loc(0);
	while (envv)
	{
		if (ft_strncmp(envv->name, var, INT32_MAX) == SUCCESS)
		{
			free((void *)envv->content);
			free((void *)envv->name);
			prev->next = envv->next;
			if (*env == envv)
				(*env) = prev->next;
			return (free((void *)envv));
		}
		prev = envv;
		envv = envv->next;
	}
	stat_loc(1);
}

void	unset(t_cmd cmd)
{
	int	i;

	i = 0;
	stat_loc(0);
	while (cmd->arv[i])
	{
		if (!cmd->arv[i] || cmd->arv[i][0] == '$'
			|| cmd->arv[i][0] == '\'' || cmd->arv[i][0] == '\"')
		{
			stat_loc(1);
			ft_err("unset: not enough arguments", 109);
			i++;
		}
		else
			unset_envv(cmd->arv[i++]);
	}
	close_fd(cmd->in, cmd->out);
	cmd->out = 1;
	cmd->in = 0;
}
