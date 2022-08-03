/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 08:31:09 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/02 14:20:02 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/shell.h"

void	ft_lstadd_back(t_env_v **lst, t_env_v *new)
{
	t_env_v	*p;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next)
		p = p->next;
	p->next = new;
}

t_list	*ft_create_list_for_tockens(_2d_arr splitted)
{
	t_list	*head;
	t_list	*new;
	int		i;

	i = 0;
	head = ft_create_a_new_node(splitted[i++]);
	while (splitted[i])
	{
		new = ft_create_a_new_node(splitted[i]);
		ft_lstadd_back_doubly(&head, new);
		i++;
	}
	return (head);
}

_str	ft_get_type(_str tocken)
{
	if (ft_memcmp(tocken, "(", 2) == 0)
		return ("l_par");
	if (ft_memcmp(tocken, ")", 2) == 0)
		return ("r_par");
	if (ft_memcmp(tocken, "|", 2) == 0)
		return ("PIPE");
	if (ft_memcmp(tocken, ">", 2) == 0)
		return ("OUT_RED");
	if (ft_memcmp(tocken, "<", 2) == 0)
		return ("IN_RED");
	if (ft_memcmp(tocken, "&&", 3) == 0)
		return ("t_AND");
	if (ft_memcmp(tocken, "||", 3) == 0)
		return ("t_OR");
	if (ft_memcmp(tocken, ">>", 3) == 0)
		return ("APPEND_OUT_RED");
	if (ft_memcmp(tocken, "<<", 3) == 0)
		return ("HEREDOC");
	else
		return ("word");
}

void	ft_lstadd_back_doubly(t_list **lst, t_list *new)
{
	t_list		*temp;
	static int	i;

	if (lst)
	{
		i++;
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

t_list	*ft_create_a_new_node(_str string)
{
	int				i;
	t_list			*new;

	new = ft_calloc(1, sizeof(t_list));
	if (!new)
		return (NULL);
	i = 0;
	new->tocken = string;
	new->type = ft_get_type(string);
	new->prev = NULL;
	new->next = NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

t_env_v	*new_env(_str str)
{
	t_env_v	*new;
	_2d_arr split;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	split =(_2d_arr) ft_split(str, '=');
	new->name = split[0];
	new->value = split[1];
	new->next = NULL;
	return (new);
}
