/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:26:42 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/23 19:19:02 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	set_env(t_str var)
{
	t_envv	**env;
	t_envv	*envv;
	t_ptr	ptr;

	env = my_env(NULL, _GET);
	envv = *env;
	while (envv)
	{
		if (ft_strncmp(envv->name, var, INT32_MAX) == SUCCESS)
		{
			if (envv->content)
				free((void *)envv->content);
			ptr = ft_memchr(var, '=', INT32_MAX);
			envv->content = ft_substr(ptr, 1, INT32_MAX);
			return ;
		}
		envv = envv->next;
	}
	env_proc(NULL, var);
}

static t_envv	*get_next_sort(t_envv *env)
{
	t_envv		*temp1;
	t_envv		*temp2;

	temp1 = env;
	temp2 = env;
	while (temp1)
	{
		if (temp1->sort && 0 < ft_strncmp(temp2->name, temp1->name, INT32_MAX))
			temp2 = temp1;
		temp1 = temp1->next;
	}
	if (temp2->sort == false)
		return (NULL);
	return (temp2);
}

static void	ex_port(t_cmd cmd)
{
	t_envv	**env;
	t_envv	*envv;

	env = my_env(NULL, _GET);
	envv = get_next_sort(*env);
	while (envv)
	{
		envv->sort = false;
		write(cmd->out, "declare -x ", 12);
		write(cmd->out, envv->name, ft_strlen(envv->name));
		write(cmd->out, "=\"", 2);
		write(cmd->out, envv->content, ft_strlen(envv->content));
		write(cmd->out, "\"\n", 2);
		envv = get_next_sort(*env);
	}
	envv = *env;
	while (envv)
	{
		envv->sort = true;
		envv = envv->next;
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
	if (!cmd->arv[1])
		return (ex_port(cmd));
	while (cmd->arv[++i])
		set_env(cmd->arv[i]);
}
