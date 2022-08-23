/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:34:19 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/23 13:46:53 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"


t_env	**my_env(t_env **env, t_req ord)
{
	static t_env	**envr;

	if (ord == SAVE)
		envr = env;
	env = envr;
	return (env);
}

static t_env	*new_env(t_str str)
{
	t_env	*new;

	new = (t_env *) ft_calloc(1, sizeof(new));
	if (!new)
		return (NULL);
	new->content = ft_strdup(ft_memchr(str, '=', INT32_MAX));
	new->name = ft_substr(str, 0, ft_strlen(str) - ft_strlen(new->content));
	new->content = ft_substr(new->content, 1, INT32_MAX);
	new->next = NULL;
	new->sort = 1;
	return (new);
}

static void	add_to_env(t_env **env, t_env *new)
{
	t_env	*temp;

	if (env == NULL)
		*env = new;
	else
	{
		temp = *env;
		while (temp->next != NULL){
			temp = temp->next;}
		temp->next = new;
	}
}

void	env_proc(char **env_v, t_str var)
{
	t_env	**env;
return ;
	env = my_env(NULL, _GET);
	if (!env)
		env = (t_env **)malloc(sizeof(env));
	if (var)
		add_to_env(env, new_env(var));
	else if (env_v && *env_v)
	{
		while (*env_v)
			add_to_env(env, new_env(*env_v++));
	}
	my_env(env, SAVE);
}
