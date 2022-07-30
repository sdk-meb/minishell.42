/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 08:31:09 by rel-hach          #+#    #+#             */
/*   Updated: 2022/07/26 15:43:36 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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

int	ft_strcmp(char *s1, char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (str1[i] - str2[i]);
}

char	*ft_get_type(char *tocken)
{
	if (ft_strcmp(tocken, "(") == 0)
		return ("l_par");
	if (ft_strcmp(tocken, ")") == 0)
		return ("r_par");
	if (ft_strcmp(tocken, "|") == 0)
		return ("PIPE");
	if (ft_strcmp(tocken, ">") == 0)
		return ("OUT_RED");
	if (ft_strcmp(tocken, "<") == 0)
		return ("IN_RED");
	if (ft_strcmp(tocken, "&&") == 0)
		return ("t_AND");
	if (ft_strcmp(tocken, "||") == 0)
		return ("t_OR");
	if (ft_strcmp(tocken, ">>") == 0)
		return ("APPEND_OUT_RED");
	if (ft_strcmp(tocken, "<<") == 0)
		return ("HEREDOC");
	else
		return ("word");
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;
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

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = (void *)malloc(count * size);
	if (!str)
	{
		return (NULL);
	}
	ft_bzero (str, count * size);
	return ((void *)(str));
}

t_list	*ft_create_a_new_node(char *string)
{
	int				i;
	static int		pipe_position;
	int				ret;
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
