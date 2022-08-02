/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:56:05 by mes-sadk          #+#    #+#             */
/*   Updated: 2021/11/22 13:12:38 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*pal;
	t_list	*p;

	if (!lst)
		return (NULL);
	pal = (t_list *)ft_calloc(sizeof(t_list), 1);
	pal->content = f(lst->content);
	if (!pal)
		ft_lstdelone(pal, del);
	p = pal;
	while (lst->next && pal)
	{
		lst = lst->next;
		pal->next = (t_list *)ft_calloc(sizeof(t_list), 1);
		if (!pal->next)
		{
			ft_lstclear(&p, del);
			return (NULL);
		}
		pal->next->content = f(lst->content);
		pal = pal->next;
	}
	return (p);
}
