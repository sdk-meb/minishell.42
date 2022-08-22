/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:26:42 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/22 00:14:00 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	set_env(t_str var)
{
	char	**env;
	int		i;
	t_ptr	ptr;

	i = -1;
	env = my_env(NULL, _GET);
	while (env[++i])
	{
		ptr = ft_strchr(env[i], '=');
		if (!ft_memcmp(env[i], var, ft_strlen(env[i]) - ft_strlen(ptr) + 1))
		{
			free(env[i]);
			env[i] = ft_substr(var, 0, ft_strlen(var));
			return ;
		}
	}
	env_proc(env, var, _ADD);
}

static int	get_next_sort(const char **env)
{
	static char	*asc;
	int			arr[2];

	arr[1] = -1;
	if (!asc)
	{
		while (env[++arr[1]])
			arr[0] = 0;
		asc = (char *)ft_calloc(++arr[1] + 1, 1);
	}
	arr[0] = 0;
	while (asc[arr[0]])
		arr[0]++;
	arr[1] = -1;
	while (env[++arr[1]])
	{
		if (!asc[arr[1]] && 0 <= ft_memcmp(env[arr[0]], env[arr[1]], INT32_MAX))
			arr[0] = arr[1];
	}
	asc[arr[0]] = 1;
	if (!env[arr[0]])
		free((void *)asc);
	return (arr[0]);
}

static void	ex_port(t_cmd cmd)
{
	char	**env;
	int		i;
	t_ptr	ptr;

	(void)cmd;
	env = my_env(NULL, _GET);
	while (1)
	{
		i = get_next_sort((const char **)env);
		if (!env[i])
			break ;
		ptr = ft_strchr(env[i], '=');
		printf("declare -x %s\"%s\"\n",
			ft_substr(env[i], 0, ft_strlen(env[i]) - ft_strlen(ptr) + 1),
			ptr + 1);
	}
}

void	export(t_cmd cmd)
{
	int	i;

	i = 0;
	while (cmd->cm->arv[++i])
		set_env(cmd->cm->arv[i]);
	if (!cmd->cm->arv[1])
		fork_exec(cmd, ex_port);
}
