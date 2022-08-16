/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:26:38 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/16 15:01:01 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

char	**ft_readline(void)
{
	char	*line;
	int		i;
	char	**splitted;

	i = 0;
	line = readline("minishell-> ");
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

void	ft_call_shell(void)
{
	char	**splitted;
	t_list	*root;

	splitted = ft_readline();
	while (1)
	{
		if (splitted && *splitted)
		{
			root = ft_create_list_for_tockens(splitted);
			free (splitted);
			root = ft_create_astree(root);
			print_tree(root);
		}
		splitted = ft_readline();
	}
}
