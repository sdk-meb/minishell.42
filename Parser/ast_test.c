/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 02:01:08 by rel-hach          #+#    #+#             */
/*   Updated: 2022/07/25 02:03:26 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*get_right_pipe_or_cmd(t_list *lst)
{
	t_list	*temp;

	temp = lst->next;
	while (temp != NULL)
	{
		if (ft_strcmp(temp->tocken, "|") == 0)
			return (temp);
		else if (ft_is_operator(temp->tocken))
			return (NULL);
		temp = temp->next;
	}
	return (NULL);
}

t_list	*get_the_left_operator_or_cmd(t_list *lst_operator)
{
	t_list	*temp;

	temp = lst_operator->prev;
	while (temp != NULL)
	{
		if (ft_is_operator(temp->tocken))
			return (temp);
		temp = temp->prev;
	}
	return (NULL);
}

t_list	*ft_create_astree(t_list *head)
{
	t_list	*temp;
	t_list	*temp2;
	t_list	*root_op;
	t_list	*root_pp;
	int		i;

	i = 0;
	temp = head;
	while (temp != NULL)
	{
		if (ft_strcmp(temp->tocken, "|") == 0)
		{
			
		}
		// if (ft_is_operator(temp->tocken))
		// {
		// 	if (ret = NULL)
		// 		temp->left = temp->prev;
		// 	else 
		// 		temp->left = 
		// }
		temp = temp->next;
	}
	return (temp2);
}
