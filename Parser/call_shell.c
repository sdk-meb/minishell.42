/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:26:38 by rel-hach          #+#    #+#             */
/*   Updated: 2022/09/02 18:41:53 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

// colour will be removed -> readline error
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

	i = 0;
	glb_sig(RL_STATE_READCMD);
	line = readline(prompt(ps1));
	glb_sig(_EXECUTE_OK);
	if (!line)
		ft_exit (1, PRIO_PROCESS + 1);
	else if (!*line)
		return (free(line), ft_readline(ps1));
	while (line[i] && ft_isprint(line[i]))
		i++;
	add_history(line);
	if (!ft_check_line(line))
	{
		line = ft_repair_string(line);
		splitted = ft_tokenize_line(line);
		return (free(line), splitted);
	}
	return (free(line), NULL);
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
			free (splitted);
			root = ft_create_astree(root);
			save_get_cmd((void **)&root);
			sh_exec(root);
			free_tree(root);
			root = NULL;
		}
	}
}
