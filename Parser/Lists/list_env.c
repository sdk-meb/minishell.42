/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:13:10 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/23 09:48:33 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

t_env	*ft_lstlast_env(t_env *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize_env(t_env *lst)
{
	int		size;
	t_env	*temp;

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

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*temp;

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
		}
	}
}

t_env	*ft_new_env(char *str)
{
	t_env	*new;
	int		i;
	char	**ptr;

	new = ft_calloc(1, sizeof(t_env));
	if (!new)
		return (NULL);
	i = 0;
	ptr = ft_split(str, '=');
	new->name = ptr[0];
	new->content = ptr[1];
	new->next = NULL;
	return (new);
}

t_env	*ft_create_list_for_env(char **splitted)
{
	t_env	*head;
	t_env	*new;
	int		i;

	i = 0;
	head = ft_new_env(splitted[i++]);
	while (splitted[i])
	{
		new = ft_new_env(splitted[i]);
		ft_lstadd_back(&head, new);
		i++;
	}
	return (head);
}
