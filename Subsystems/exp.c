/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:26:42 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/16 16:07:50 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	init_env(void)
{
	t_str	str;

	set_env("SHELL=./minishell");
	str = get_env("PATH");
	if (!str || !*str)
		set_env("PATH=/usr/local/bin:/bin:/usr/bin:/bin\n\e[A\e[K\e[A");
	if (!ft_memcmp(get_env("SHLVL"), "-", 1) && ft__env("./minishell"))
		set_env(ft_strjoin("SHLVL=", "-1"));
	set_env(ft_strjoin("SHLVL=", ft_itoa(ft_atoi(get_env("SHLVL")) + 1)));
	str = getcwd(NULL, OPEN_MAX);
	set_env(ft_strjoin("PWD=", str));
	current_path((t_path) get_env("PWD"));
	free(str);
	unset_envv("_");
	unset_envv("OLDPWD");
}

static void	opr_plus_eq(t_cmd cmd, int c, int arg)
{
	char	*name;
	char	*tenor;
	int		i;

	i = 0;
	name = ft_substr(cmd->arv[arg], 0, c + 1);
	name[c] = 0;
	tenor = get_env(name);
	while (tenor[i] && tenor[i] != '\n')
		i++;
	tenor [i] = '\00';
	name[c] = '=';
	name = ft_strjoin(name, tenor);
	cmd->arv[arg] = ft_strjoin(name, \
		ft_substr(cmd->arv[arg], c + 2, MAX_INPUT));
}

static bool	check_if(t_req ord, char **av, int ac[2])
{
	if (ord == 0)
	{
		if ((av[ac[0]][ac[1]] == '+' && av[ac[0]][ac[1] + 1] != '=')
		|| ((av[ac[0]][++ac[1]] && av[ac[0]][ac[1]] != '='
		&& av[ac[0]][ac[1]] != '+') || !ac[1]))
			return (1);
		return (0);
	}
	if (ord == 1)
	{
		if (av[ac[0]][ac[1]] && (av[ac[0]][ac[1]] != '=' || !ac[1]) && !(ac[1]
			&& av[ac[0]][ac[1]] == '+' && av[ac[0]][ac[1] + 1] == '='))
			return (1);
		return (0);
	}
	return (0);
}

void	export(t_cmd cmd)
{
	int		ac[2];
	char	**av;

	av = cmd->arv;
	ac[0] = 0;
	stat_loc(0);
	if (!av[1])
		return (fork_exec(cmd, ex_port));
	while (av[++ac[0]])
	{
		ac[1] = -1;
		while (check_if(0, av, ac))
			if ((ft_isalpha(av[ac[0]][ac[1]]) && ft_isdigit(av[ac[0]][ac[1]])
					&& av[ac[0]][ac[1]] != '_'))
				break ;
		if (ac[1] && av[ac[0]][ac[1]] == '+' && av[ac[0]][ac[1] + 1] == '=')
			opr_plus_eq(cmd, ac[1], ac[0]);
		if (ft_isalpha(av[ac[0]][0]) && av[ac[0]][0] != '_')
			ac[1] = 0;
		if (check_if(1, av, ac) && stat_loc(1))
			ft_err("msh: export: not a valid identifier", 109);
		else
			set_env(av[ac[0]]);
	}
	return (close_fd(&(cmd->in), &(cmd->out)), unset_envv("_"));
}
