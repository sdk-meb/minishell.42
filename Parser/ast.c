/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:49:22 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/31 21:57:53 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Include/minishell.h"

t_list	*return_first_node(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp->prev != NULL && ft_memcmp(temp->prev->token, "|", 2))
		temp = temp->prev;
	return (temp);
}

t_list	*ft_pipe_case(t_list *head)
{
	t_list	*temp;
	t_list	*pipe_root;

	temp = ft_lstlast(head);
	pipe_root = NULL;
	while (temp != NULL)
	{
		if (ft_memcmp(temp->token, "|", 2) == 0)
		{
			if (pipe_root == NULL)
			{
				pipe_root = temp;
				temp->right = temp->next;
			}
			else
			{
				temp->right = pipe_root;
				pipe_root = temp;
			}
			temp->prev->next = NULL;
			temp->left = return_first_node(temp->prev);
		}
		temp = temp->prev;
	}
	return (pipe_root);
}

t_list	*ft_create_astree(t_list *head)
{
	t_list	*pipe_root;
	t_list	*temp;

	pipe_root = NULL;
	temp = head;
	pipe_root = ft_pipe_case(temp);
	if (pipe_root)
		return (pipe_root);
	return (head);
}
