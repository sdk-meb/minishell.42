/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:33:54 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/13 13:31:40 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Include/minishell.h"

bool	ft_is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (SUCCESS);
	else
		return (FAILURE);
}

bool	ft_is_pipe(char c)
{
	if (c == '|')
		return (SUCCESS);
	else
		return (FAILURE);
}

bool	ft_is_redirection(char c)
{
	if (c == '>' || c == '<')
		return (SUCCESS);
	else
		return (FAILURE);
}

bool	ft_is_special(char c)
{
	if (ft_is_pipe(c) && ft_is_redirection(c))
		return (FAILURE);
	return (SUCCESS);
}

void	print_tree(t_list *root)
{
	if (root == NULL)
	{
		printf("%s\n", "NULL");
		return ;
	}
	printf("                     I AM ROOT == %s\n", root->token);
	if (root->left)
		printf("MY LEFT IS [%s]", root->left->token);
	if (root->right)
		printf("				  MY RIGHT IS [%s]\n", root->right->token);
	print_tree(root->left);
	print_tree(root->right);
}
