/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:26:38 by rel-hach          #+#    #+#             */
/*   Updated: 2022/09/10 22:29:36 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static char	*prompt(char ps1)
{
	if (!ft_memcmp(get_env("USER"), "ROOT", 5))
		return ("M-Shell #> ");
	else if (ps1 == PRIO_USER)
		return ("M-Shell $> ");
	return (NULL);
}

char	**ft_readline(char ps1)
{
	char	*line;
	char	**splitted;
	char	*p;

	glb_sig(RL_STATE_READCMD);
	line = readline(prompt(ps1));
	p = line;
	if (!line)
		return (printf("\r\e[AM-Shell $> \e[K"), ft_exit (stat_loc(EMPTY)), NULL);
	else if (!*line)
		return (free(p), ft_readline(ps1));
	glb_sig(_EXECUTE_OK);
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
			sh_exec(root, 0);
		}
		c_delete(TEMPORARY, EMPTY);
		root = NULL;
	}
}
