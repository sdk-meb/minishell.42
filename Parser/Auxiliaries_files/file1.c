/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:33:54 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/18 22:51:12 by mes-sadk         ###   ########.fr       */
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
		printf("%s\n", (void *)root);
		return ;
	}
	printf("                     I AM ROOT == %c\n", root->type);
	if (root->left)
		printf("MY LEFT IS [%c]", root->left->type);
	if (root->right)
		printf("				  MY RIGHT IS [%c]\n", root->right->type);
	print_tree(root->left);
	print_tree(root->right);
}