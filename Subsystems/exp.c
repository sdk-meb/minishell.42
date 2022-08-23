/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:26:42 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/23 13:43:27 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	set_env(t_str var)
{
	t_env	**env;

	env = my_env(NULL, _GET);
	while (*env)
	{
		if (ft_memcmp((*env)->name, var, INT32_MAX) == SUCCESS)
		{
			(*env)->content = ft_strdup(var);
			return ;
		}
	}
	env_proc(NULL, var);
}

static t_env	*get_next_sort(t_env *env)
{
	t_env		*temp1;
	t_env		*temp2;

	temp1 = env;
	temp2 = env;
	while (temp1)
	{
		if (0 < ft_memcmp(temp2->name, temp1->name, INT32_MAX) && temp1->sort)
			temp2 = temp1;
	}
	return (temp2);
}

static void	ex_port(t_cmd cmd)
{
	t_env	**env;
	t_env	*temp;

	env = my_env(NULL, _GET);
	temp = *env;
	while (temp)
	{
		temp = get_next_sort(*env);
		temp->sort = 0;
		write(cmd->out, "declare -x ", 12);
		write(cmd->out, temp->name, INT32_MAX);
		write(cmd->out, "=\"", 2);
		write(cmd->out, "\"", 1);
	}
	temp = *env;
	while (temp)
	{
		temp->sort = 1;
		temp = temp->next;
	}
	if (cmd->out != STDOUT_FILENO)
		close(cmd->out);
	if (cmd->in != STDIN_FILENO)
		close(cmd->in);
}

void	export(t_cmd cmd)
{
	int	i;

	i = 0;
	while (cmd->arv[++i])
		set_env(cmd->arv[i]);
	if (!cmd->arv[1])
		ex_port(cmd);
}
