/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:32:08 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/15 05:22:23 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	init_env(void)
{
	t_str	str;

	set_env("SHELL=./minishell");
	if (!ft_memcmp(get_env("SHLVL"), "-", 1) && ft__env("./minishell"))
		set_env(ft_strjoin("SHLVL=", "-1"));
	set_env(ft_strjoin("SHLVL=", ft_itoa(ft_atoi(get_env("SHLVL")) + 1)));
	str = getcwd(NULL, OPEN_MAX);
	set_env(ft_strjoin("PWD=", str));
	current_path((t_path) get_env("PWD"));
	free(str);
	unset_envv("_");
	unset_envv("OLDPWD");
	str = get_env("PATH");
	if (!str || !*str)
		set_env("PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin");
}

void	unset_envv(t_str var)
{
	t_envv	**env;
	t_envv	*envv;
	t_envv	*prev;

	env = my_env(NULL, _GET);
	envv = *env;
	prev = *env;
	stat_loc(0);
	while (envv)
	{
		if (ft_strncmp(envv->name, var, INT32_MAX) == SUCCESS)
		{
			prev->next = envv->next;
			if (*env == envv)
				(*env) = prev->next;
			return ;
		}
		prev = envv;
		envv = envv->next;
	}
}

void	*ft__env(t_str arg)
{
	static t_str	_env_;
	t_ptr			ptr;
	int				lenth;

	if (arg)
	{
		lenth = ft_strlen(arg);
		ptr = malloc(lenth + 1);
		ft_memmove(ptr, arg, lenth + 1);
		free ((void *)_env_);
		_env_ = ptr;
	}
	return ((void *) _env_);
}

t_path	current_path(t_path path)
{
	static t_path	save_path;

	if (path && *path)
		save_path = path;
	return (save_path);
}

void	unset(t_cmd cmd)
{
	int	arg;
	int	c;

	arg = 0;
	stat_loc(0);
	while (cmd->arv[++arg])
	{
		c = -1;
		while (cmd->arv[arg][++c])
			if (ft_isalpha(cmd->arv[arg][c]) && ft_isdigit(cmd->arv[arg][c])
					&& cmd->arv[arg][c] != '_')
				break ;
		if (((ft_isalpha(cmd->arv[arg][0]) && cmd->arv[arg][0] != '_')
			|| (ft_isdigit(cmd->arv[arg][c]) && ft_isalpha(cmd->arv[arg][c]
			&& cmd->arv[arg][c] != '_'))) && cmd->arv[arg][c])
		{
			stat_loc(1);
			ft_err("unset: not enough arguments", 109);
		}
		else
			unset_envv(cmd->arv[arg]);
	}
	close_fd(&(cmd->in), &(cmd->out));
}
