/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:26:38 by rel-hach          #+#    #+#             */
/*   Updated: 2022/09/06 14:33:14 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static char	*prompt(char ps1)
{
	if (!ft_memcmp(get_env("USER"), "ROOT", 5) && stat_loc(EMPTY))
		return ("\033[4;33mM-Shell\033[0;34m $>\033[0;37m");
	if (ps1 == PRIO_USER && stat_loc(EMPTY))
		return ("\033[4;33mM-Shell\033[0;31m $>\033[0;37m");
	else if (ps1 == PRIO_USER)
		return ("\033[4;33mM-Shell\033[0;32m $>\033[0;37m");
	return (NULL);
}

char	**ft_readline(char ps1)
{
	char	*line;
	int		i;
	char	**splitted;
	char	*p;

	i = 0;
	glb_sig(RL_STATE_READCMD);
	line = readline(prompt(ps1));
	p = line;
	glb_sig(_EXECUTE_OK);
	if (!line)
		return (free(p), ft_exit (1), NULL);
	else if (!*line)
		return (free(p), ft_readline(ps1));
	while (line[i] && ft_isprint(line[i]))
		i++;
	add_history(line);
	if (!ft_check_line(line))
	{
		line = ft_repair_string(line);
		splitted = ft_tokenize_line(line);
		return (free(p), splitted);
	}
	return (free(p), NULL);
}

void	ft_call_shell(char ps1)
{
	char	**splitted;
	t_list	*root;

	while (1)
	{
		splitted = ft_readline(ps1);
		if (splitted && *splitted)
		{
			splitted = handel_heredoc(splitted);
			root = ft_create_list_for_tockens(splitted);
			root = ft_create_astree(root);
			sh_exec(root);
			c_delete(TEMPORARY, EMPTY);
			root = NULL;
		}
	}
}
