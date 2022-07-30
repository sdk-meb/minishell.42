/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:00:56 by rel-hach          #+#    #+#             */
/*   Updated: 2022/07/30 15:55:49 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*ft_pipe_case(t_list *head)
{
	t_list	*temp;
	t_list	*pipe_root;

	temp = ft_lstlast(head);
	pipe_root = NULL;
	while (temp != NULL)
	{
		if (ft_is_operator(temp->tocken))
		{
			if (pipe_root)
				temp->right = pipe_root;
			else
				temp->right = temp->next;
			pipe_root = NULL;
			temp = temp->prev;
		}
		if (ft_strcmp(temp->tocken, "|") == 0)
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
			temp->left = temp->prev;
		}
		temp = temp->prev;
	}
	return (pipe_root);
}

t_list	*ft_get_root_left_pipe_or_cmd(t_list *head)
{
	t_list	*temp;
	t_list	*root_pipe;

	temp = head;
	root_pipe = NULL;
	while (temp->prev != NULL)
	{
		if (ft_strcmp(temp->tocken, "|") == 0)
			root_pipe = temp;
		temp = temp->prev;
	}
	if (root_pipe)
		return (root_pipe);
	return (temp);
}

t_list	*ft_operator_case(t_list *head)
{
	t_list	*temp;
	t_list	*root;

	root = NULL;
	temp = head;
	while (temp != NULL)
	{
		if (ft_is_operator(temp->tocken))
		{
			if (root)
			{
				temp->left = root;
				root = temp;
			}
			if (root == NULL)
			{
				root = temp;
				temp->left = ft_get_root_left_pipe_or_cmd(temp);
			}
		}
		temp = temp->next;
	}
	return (root);
}

int	ft_is_parenth(char *str)
{
	if (!ft_strcmp(str, "(") || !ft_strcmp(str, ")"))
		return (1);
	return (0);
}

t_list	*ft_get_next_operator_or_pipe(t_list *head)
{
	t_list		*temp;
	t_list		*root;
//	t_list		*root_p;
	static int	i;

	temp = head;
	root = NULL;
//	root_p = NULL;
	while (temp != NULL)
	{
		if (ft_is_operator(temp->tocken))
			root = temp;
//		if (!ft_strcmp(temp->tocken, "|") && (i++ == 0))
//			root_p = temp;
		if (ft_is_operator(temp->tocken))
			root = temp;
		if (!ft_strcmp(temp->tocken, "|") && (i++ == 0))
			root = temp;
		temp = temp->next;
	}
	if(root)
		return (root);
	return (NULL);
}


t_list	*ft_get_prev_operator_or_pipe(t_list *head)
{
	t_list		*temp;
	t_list		*root;
//	t_list		*root_p;
//	static int	i;

	temp = head;
	root = NULL;
//	root_p = NULL;
	while (temp != NULL)
	{
		if (ft_is_operator(temp->tocken))
		{
			if (ft_is_parenth(temp->left->tocken) || ft_is_parenth(temp->right->tocken))
				return (temp);
		}
		if (!ft_strcmp(temp->tocken, "|"))
		{
			if (ft_is_parenth(temp->left->tocken) || ft_is_parenth(temp->right->tocken))
				return (temp);
		}
		if (ft_is_operator(temp->tocken))
			root = temp;
		temp = temp->prev;
	}
	if (root)
		return (root);
	return (NULL);
}

t_list	*ft_get_prev(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (ft_is_operator(temp->tocken))
				return (temp);
		if (!ft_strcmp(temp->tocken, "|"))
				return (temp);
		temp = temp->prev;
	}
	return (temp);
}

void	ft_first_step(t_list *head)
{
	t_list	*temp;

	temp = head;
	if (!ft_is_parenth(temp->prev->tocken))
		temp->left = temp->prev;
	if (!ft_is_parenth(temp->next->tocken))
		temp->next = temp->next;
}

void	paren_case(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (ft_is_operator(temp->tocken))
		{
			ft_first_step(temp);
			if (!ft_strcmp(temp->next->tocken, "("))
				temp->right = ft_get_next_operator_or_pipe(temp->next);
			if (!temp->right)
				temp->right = temp->next;
			if (!ft_strcmp(temp->prev->tocken, ")"))
				temp->left = ft_get_prev_operator_or_pipe(temp->prev);
		}
		temp = temp->next;
	}
}

t_list	*ft_create_astree(t_list *head)
{
	t_list	*pipe_root;
	t_list	*operator_root;

	pipe_root = NULL;
	operator_root = NULL;
	pipe_root = ft_pipe_case(head);
	operator_root = ft_operator_case(head);
	//paren_case(head);
	if (operator_root)
		return (operator_root);
	if (pipe_root)
		return (pipe_root);
	return (NULL);
}
