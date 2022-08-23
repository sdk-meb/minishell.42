/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:34:19 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/23 19:04:14 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"


t_envv	**my_env(t_envv **env, t_req ord)
{
	static t_envv	**envr;

	if (ord == SAVE)
		envr = env;
	env = envr;
	return (env);
}

static t_envv	*new_env(t_str str)
{
	t_envv	*new;

	new = (t_envv *) ft_calloc(1, sizeof(new));
	if (!new)
		return (NULL);
	new->content = ft_strdup(ft_memchr(str, '=', INT32_MAX));
	new->name = ft_substr(str, 0, ft_strlen(str) - ft_strlen(new->content));
	new->content = ft_substr(new->content, 1, INT32_MAX);
	new->next = NULL;
	new->sort = 1;
	return (new);
}

static void	add_to_env(t_envv **env, t_envv *new)
{
	t_envv	*temp;

	if (*env == NULL)
		*env = new;
	else
	{
		temp = *env;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

void	*get_env(t_str var)
{
	t_envv	**env;
	t_envv	*envv;

	env = my_env(NULL, _GET);
	envv = *env;
	while (envv->next)
	{
		if (ft_strncmp(envv->name, var, INT32_MAX) == SUCCESS)
			return ((void *)envv->content);
		envv = envv->next;
	}
	return ("");
}

void	env_proc(char **env_v, t_str var)
{
	t_envv	**env;

	env = my_env(NULL, _GET);
	if (!env)
		env = my_env((t_envv **)ft_calloc(sizeof(env), 1), SAVE);
	if (var)
		add_to_env(env, new_env(var));
	else if (env_v && *env_v)
	{
		while (*env_v)
			add_to_env(env, new_env(*env_v++));
	}
	my_env(env, SAVE);/* not important */
}
