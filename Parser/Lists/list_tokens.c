/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:46:05 by rel-hach          #+#    #+#             */
/*   Updated: 2022/09/01 20:07:06 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*temp;

	if (lst == NULL)
		return (0);
	size = 0;
	temp = lst;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

void	ft_lstadd_back_doubly(t_list **lst, t_list *new)
{
	t_list		*temp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp = *lst;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
			new->prev = temp;
		}
	}
}

char	ft_get_symbol(char *tocken)
{
	if (!ft_memcmp(tocken, "|", 2))
		return ('|');
	if (!ft_memcmp(tocken, ">", 2))
		return ('>');
	if (!ft_memcmp(tocken, "<", 2))
		return ('<');
	if (!ft_memcmp(tocken, ">>", 3))
		return (O_APPEND);
	if (!ft_memcmp(tocken, "<<", 3))
		return (HEREDOC);
	return ('w');
}


t_list	*ft_new_token(char *heredoc, char *string)
{
	t_list			*new;

	new = ft_calloc(1, sizeof(t_list));
	if (!new)
		return (NULL);
	new->type = string;
	if (!ft_strcmp(heredoc, "<<"))
		new->token = string;
	else
		new->token = ft_expand(string);
	new->symbol = ft_get_symbol(string);
	new->in = STDIN_FILENO;
	new->out = STDOUT_FILENO;
	new->arv = NULL;
	new->prev = NULL;
	new->next = NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

t_list	*ft_create_list_for_tockens(char **splitted)
{
	t_list	*head;
	t_list	*new;
	int		i;

	i = 0;
	head = ft_new_token(splitted[0], splitted[i++]);
	while (splitted[i])
	{
		new = ft_new_token(splitted[i - 1], splitted[i]);
		ft_lstadd_back_doubly(&head, new);
		i++;
	}
	return (head);
}

/// echo hello > file1.txt aaaaaa 
// output :	hello aaaaaa