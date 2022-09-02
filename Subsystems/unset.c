/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:32:08 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/02 16:16:29 by mes-sadk         ###   ########.fr       */
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
}

void	unset(t_cmd cmd)
{
	int	arg;
	int	c;

	arg = 0;
	stat_loc(0);
	while (cmd->arv[++arg])
	{
		c = -1;
		while (cmd->arv[arg][++c])
			if (ft_isalpha(cmd->arv[arg][c]) && ft_isdigit(cmd->arv[arg][c])
					&& cmd->arv[arg][c] != '_')
				break ;
		if (((ft_isalpha(cmd->arv[arg][0]) && cmd->arv[arg][0] != '_')
			|| (ft_isdigit(cmd->arv[arg][c]) && ft_isalpha(cmd->arv[arg][c]
			&& cmd->arv[arg][c] != '_'))) && cmd->arv[arg][c])
		{
			stat_loc(1);
			ft_err("unset: not enough arguments", 109);
		}
		else
			unset_envv(cmd->arv[arg]);
	}
	close_fd(&(cmd->in), &(cmd->out));
}
