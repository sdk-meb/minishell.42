/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:34:19 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/10 10:51:43 by mes-sadk         ###   ########.fr       */
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
	t_envv	*ev;
	size_t	i;

	env = my_env(NULL, _GET);
	ev = *env;
	i = ft_strnindex(var, '=', INT32_MAX);
	if (!i)
		i = ft_strlen(var) + 1;
	while (ev)
	{
		if (ft_strlen(ev->name) == i - 1 && !ft_strncmp(ev->name, var, i - 1))
		{
			if (ev->content && ft_strnindex(var, '=', INT32_MAX))
				ev->content = NULL;
			genus(APPROVED);
			if (ft_strnindex(var, '=', INT32_MAX))
				ev->content = get_tenor(var);
			genus(TEMPORARY);
			return ;
		}
		ev = ev->next;
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
	if (ft_strncmp(var, "_", 2) == SUCCESS)
		return (ft__env(NULL));
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
