/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 08:54:28 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/03 00:37:25 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lib/shell.h"

void	print_tree(t_list *root) /* will be removed */
{
	if (root == NULL)
		return ;
	printf("                     I AM ROOT == %s\n", root->tocken);
	if (root->left)
		printf("MY LEFT IS [%s]", root->left->tocken);
	if (root->right)
		printf("				  MY RIGHT IS [%s]\n", root->right->tocken);
	print_tree(root->left);
	print_tree(root->right);
}

void	ft_minishell(t_env env)
{
	_2d_arr	splitted;
	t_list	*head;
	t_list	*root;

	ensure_env(env);
	while (1)
	{
		splitted = ft_readline(0);
		if (splitted && *splitted)
		{	
			head = ft_create_list_for_tockens(splitted);
			root = ft_create_astree(head);
			print_tree(root);
		}
	}
}
