/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_expr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 23:15:31 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/13 13:50:46 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static t_envv	*next_declare(t_envv *env)
{
	t_envv		*temp1;
	t_envv		*temp2;

	temp1 = env;
	temp2 = env;
	while (temp2 && temp2->sort == false)
		temp2 = temp2->next;
	while (temp1 && temp2)
	{
		if (temp1->sort && 0 < ft_strncmp(temp2->name, temp1->name, INT32_MAX))
			temp2 = temp1;
		temp1 = temp1->next;
	}
	if (!temp2 || temp2->sort == false)
		return (NULL);
	return (temp2);
}

static void	write_exp(t_cmd cmd, t_envv	*envv)
{
	write(cmd->out, "declare -x ", 11);
	write(cmd->out, envv->name, ft_strlen(envv->name));
	if (envv->content)
	{
		write(cmd->out, "=\"", 2);
		write(cmd->out, envv->content, ft_strlen(envv->content));
		write(cmd->out, "\"", 1);
	}
	write(cmd->out, "\n", 1);
	envv->sort = false;
}

void	ex_port(t_cmd cmd)
{
	t_envv	**env;
	t_envv	*envv;

	env = my_env(NULL, _GET);
	envv = next_declare(*env);
	while (envv)
	{
		write_exp(cmd, envv);
		envv = next_declare(*env);
	}
	envv = *env;
	while (envv)
	{
		envv->sort = true;
		envv = envv->next;
	}
	ft_exit (0);
}
