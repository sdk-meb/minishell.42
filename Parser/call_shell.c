/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:26:38 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/31 23:58:32 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static char	*prompt(char ps1)
{
	if (!ft_memcmp(get_env("USER"), "ROOT", 5))
		return ("msh~1.0#>");
	if (ps1 == PRIO_USER)
		return ("msh~1.0$>");
	return (NULL);
}

char	**ft_readline(char ps1)
{
	char	*line;
	int		i;
	char	**splitted;

	i = 0;
	glb_sig(SIGINT);
	line = readline(prompt(ps1));
	glb_sig(SIGCHLD);
	if (!line)
		ft_exit (1);
	else if (!*line)
		return (ft_readline(ps1));
	while (line && line[i] && ft_isprint(line[i]))
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
			sh_exec(root);
		}
	}
}
