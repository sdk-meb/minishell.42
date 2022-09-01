/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:34:19 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/01 19:22:30 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static t_str	get_name(t_str strr)
{
	char	*str;
	int		cas_e;

	str = (char *)strr;
	cas_e = 0;
	if (!str)
		return (NULL);
	while (str[cas_e] && str[cas_e] != '=')
		cas_e++;
	return (ft_substr(str, 0, cas_e));
}

t_str	get_tenor(t_str strr)
{
	int		cas_e;
	char	*str;

	str = (char *)strr;
	cas_e = 0;
	if (!str)
		return (NULL);
	while (str[cas_e] && str[cas_e] != '=')
		cas_e++;
	if (str[cas_e] == '=')
		return (ft_substr(str, cas_e + 1, ft_strlen(str) - cas_e + 1));
	return (NULL);
}

static t_envv	*new_env(t_str str)
{
	t_envv	*new;

	new = (t_envv *) ft_calloc(1, sizeof(new));
	if (!new)
		return (NULL);
	get_tenor(str);
	get_name(str);
	new->content = get_tenor(str);
	new->name = get_name(str);
	new->next = NULL;
	new->sort = true;
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
		set_env(ft_strjoin("SHLVL=", ft_itoa(ft_atoi(get_env("SHLVL")) + 1)));
		set_env("SHELL=./minishell");
		unset_envv("_");
	}
}
