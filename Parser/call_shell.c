/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:26:38 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/13 22:42:31 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Include/minishell.h"

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
		printf("%s\n", line);
		splitted = ft_branch_line(line, ' ');
		return (free(line), splitted);
	}
	return (free(line), NULL);
}

void	ft_call_shell(void)
{
	char	**splitted;
	t_list	*root;

	
	while (1)
	{
		splitted = ft_readline();
		if (splitted && *splitted)
		{
			puts("hello\n");
			root = ft_create_list_for_tockens(splitted);
			root = ft_create_astree(root);
			print_tree(root);
			free (splitted);
		}
		sh_exece((t_cmd*)root);
	}
}
