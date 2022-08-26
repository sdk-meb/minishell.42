/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:26:38 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/20 18:35:08 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static char	*prompt(char ps1)
{
	if (!ft_memcmp(_get_env("USER"), "ROOT", 5))
		return (ft_strdup("msh~1.0#>"));
	if (ps1 == PRIO_USER)
		return (ft_strdup("msh~1.0$>"));
	return (NULL);
}

char	**ft_readline(char ps1)
{
	char	*line;
	int		i;
	char	**splitted;

	i = 0;
	line = readline(prompt(ps1));
	if (!line)
		exit (1);
	else if (!*line)
		return (ft_readline(PRIO_USER));
	while (line && line[i] && ft_isprint(line[i]))
		i++;
	if (!line || !line[i])
		return (NULL);
	add_history(line);
	if (!ft_check_line(line))
	{
		line = ft_repair_string(line);
		splitted = ft_branch_line(line, ' ');
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
			//print_tree(root);
		}
	}
}
