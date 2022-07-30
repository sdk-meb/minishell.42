/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_par.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:19:59 by rel-hach          #+#    #+#             */
/*   Updated: 2022/07/27 14:56:20 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*ft_get_right_operator(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (ft_is_operator(temp->tocken))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

t_list	*ft_get_left_operator(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (ft_is_operator(temp->tocken))
			return (temp);
		temp = temp->prev;
	}
	return (NULL);
}

t_list	*ft_right(t_list	*head)
{
	t_list	*temp;

	temp = head;
	if (ft_strcmp(temp->next->type, "word"))
		temp->right = temp->next;
	else 
		temp->right = ft_get_right_operator(temp);
	return (temp->right);
}

t_list	*ft_left(t_list	*head)
{
	t_list	*temp;

	temp = head;
	if (ft_strcmp(temp->prev->type, "word"))
		temp->left = temp->prev;
	else 
		temp->left = ft_get_left_operator(temp);
	return (temp->left);
}

t_list	*ft_create_tree_get_root(t_list *head)
{
	t_list	*temp;
	t_list	*root;

	root = NULL;
	while (temp != NULL)
	{
		if (ft_is_operator(temp->tocken))
		{
			root = temp;
			temp->left = ft_left(temp);
			temp->right = ft_right(temp);
			return (root);
		}
		temp = temp->next;
	}
	return (root);
}

t_list	*ft_create_astree_for_parenthesis(t_list *head)
{
	t_list	*root;

	root = NULL;
	root = ft_create_tree_get_root(head);
	if (root)
		return (root);
	return (NULL);
}