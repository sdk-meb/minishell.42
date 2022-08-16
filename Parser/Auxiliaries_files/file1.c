/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:33:54 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/14 15:35:51 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

int	ft_is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	else
		return (0);
}

int	ft_is_pipe(char c)
{
	if (c == '|')
		return (1);
	else
		return (0);
}

int	ft_is_redirection(char c)
{
	if (c == '>' || c == '<')
		return (1);
	return (0);
}

int	ft_is_special(char c)
{
	if (ft_is_pipe(c) || ft_is_redirection(c))
		return (1);
	return (0);
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
