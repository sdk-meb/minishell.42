/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:34:19 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/04 12:53:33 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

t_envv	**my_env(t_envv **env, t_req ord)
{
	static t_envv	**envr;

	if (ord == SAVE)
		envr = env;
	return (envr);
}

char	**env_to_argv(t_envv **env)
{
	t_envv	*mng;
	int		size;
	char	**argv;

	size = 0;
	mng = *env;
	while (size++, mng)
		mng = mng->next;
	mng = *env;
	argv = (t_head) ft_calloc(sizeof(argv), size);
	argv[--size] = NULL;
	while (mng)
	{
		argv[--size] = ft_strjoin(mng->name, "=");
		argv[size] = ft_strjoin(argv[size], mng->content);
		mng = mng->next;
	}
	return (argv);
}

void	set_env(t_str var)
{
	t_envv	**env;
	t_envv	*envv;
	int		i;

	env = my_env(NULL, _GET);
	envv = *env;
	i = ft_strnindex(var, '=', INT32_MAX);
	if (!i)
		i = ft_strlen(var) + 1;
	while (envv)
	{
		if (ft_strncmp(envv->name, var, i - 1) == SUCCESS)
		{
			if (envv->content && ft_strnindex(var, '=', INT32_MAX))
			{
				envv->content = NULL;
			}
			if (ft_strnindex(var, '=', INT32_MAX))
				envv->content = get_tenor(var);
			return ;
		}
		envv = envv->next;
	}
	env_proc(NULL, var);
}

void	env(t_cmd cmd)
{
	t_envv	**env;
	t_envv	*envv;

	env = my_env(NULL, _GET);
	envv = *env;
	while (envv)
	{
		if (envv->content)
		{
			write(cmd->out, envv->name, ft_strlen(envv->name));
			write(cmd->out, "=", 2);
			write(cmd->out, envv->content, ft_strlen(envv->content));
			write(cmd->out, "\n", 2);
		}
		envv = envv->next;
	}
	write(cmd->out, "_=/usr/bin/env\n", 16);
	ft_exit (0);
}

void	*get_env(t_str var)
{
	t_envv	**env;
	t_envv	*envv;

	if (ft_strncmp(var, "?", 2) == SUCCESS)
		return (ft_itoa(stat_loc(EMPTY)));
	env = my_env(NULL, _GET);
	if (!env)
		return ("");
	envv = *env;
	while (envv)
	{
		if (ft_strcmp(envv->name, var) == SUCCESS)
		{
			if (envv->content)
				return ((void *)envv->content);
			break ;
		}
		envv = envv->next;
	}
	return ("");
}
