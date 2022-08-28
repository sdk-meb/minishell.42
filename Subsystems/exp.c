/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:26:42 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/28 11:39:08 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	set_env(t_str var)
{
	t_envv	**env;
	t_envv	*envv;
	int		i;

	env = my_env(NULL, _GET);
	envv = *env;
	i = ft_strnindex(var, '=', INT32_MAX);
	if (!i)
		i = ft_strlen(var);
	while (envv)
	{
		if (ft_strncmp(envv->name, var, i - 1) == SUCCESS)
		{
			if (envv->content)
				free((void *)envv->content);
			envv->content = ft_substr(var, i, INT32_MAX);
			return ;
		}
		envv = envv->next;
	}
	env_proc(NULL, var);
}

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

static void	ex_port(t_cmd cmd)
{
	t_envv	**env;
	t_envv	*envv;

	env = my_env(NULL, _GET);
	envv = next_declare(*env);
	while (envv)
	{
		envv->sort = false;
		write(cmd->out, "declare -x ", 12);
		write(cmd->out, envv->name, ft_strlen(envv->name));
		if (envv->eq == true)
		write(cmd->out, "=\"", 2);
		write(cmd->out, envv->content, ft_strlen(envv->content));
		write(cmd->out, "\"\n", 2);
		envv = next_declare(*env);
	}
	envv = *env;
	while (envv)
	{
		envv->sort = true;
		envv = envv->next;
	}
	close_fd(cmd->in, cmd->out);
}

void	export(t_cmd cmd)
{
	int	arg;
	int	c;

	arg = 0;
	if (!cmd->arv[1])
		return (ex_port(cmd));
	while (cmd->arv[++arg])
	{
		c = -1;
		while (cmd->arv[arg][++c] && (cmd->arv[arg][c] != '=' || !c))
			if (ft_isalpha(cmd->arv[arg][c]) && cmd->arv[arg][c] != '_')
				break ;
		if (cmd->arv[arg][c] && (cmd->arv[arg][c] != '=' || !c))
			ft_err("msh: export: not a valid identifier", 109);
		else
			set_env(cmd->arv[arg]);
	}
	unset_envv("_");
	cmd->out = 1;
	cmd->in = 0;
}
