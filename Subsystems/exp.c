/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:26:42 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/11 23:18:18 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	opr_plus_eq(t_cmd cmd, int c, int arg)
{
	char	*name;
	char	*tenor;

	name = ft_substr(cmd->arv[arg], 0, c + 1);
	name[c] = 0;
	tenor = get_env(name);
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
		if (check_if(1, av, ac))
			return (ft_err("msh: export: not a valid identifier", 109));
		set_env(av[ac[0]]);
	}
	return (close_fd(&(cmd->in), &(cmd->out)), unset_envv("_"));
}
