/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_chap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 00:24:18 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/27 22:08:42 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_heapdelone(t_heap *heap)
{
	if (!heap)
		return ;
	free(heap->dng_ptr);
	free(heap);
}

static void	ft_heapclear(t_heap **heap)
{
	t_heap	*p;

	if (!heap || !*heap)
		return ;
	p = *heap;
	*heap = p->extra;
	ft_heapclear(heap);
	ft_heapdelone(p);
}

t_heap	**governor(t_req ord)
{
	static t_heap	**glb;
	static t_heap	**tmp;

	if ((ord & APPROVED) == APPROVED && (ord & _GET) == _GET && glb)
		return (glb);
	else if ((ord & TEMPORARY) == TEMPORARY && (ord & _GET) == _GET && tmp)
		return (tmp);
	else if ((ord & APPROVED) == APPROVED)
	{
		glb = (t_heap **)ft_calloc(sizeof(glb), 1);
		*glb = NULL;
		return (glb);
	}
	else if ((ord & TEMPORARY) == TEMPORARY)
	{
		tmp = (t_heap **)ft_calloc(sizeof(tmp), 1);
		*tmp = NULL;
		return (tmp);
	}
	return (NULL);
}

void	c_delete(t_req ord, int dangel)
{
	t_heap	**mnger;
	t_heap	*mng;
	t_heap	*ref;

	mnger = governor(ord & _GET);
	if (!mnger)
		return ;
	if (dangel < 0)
		return (ft_heapclear(mnger));
	ref = (*mnger);
	while (1 && mnger && *mnger)
	{
		if ((*mnger)->extra->dangel == dangel)
		{
			mng = (*mnger)->extra;
			(*mnger)->extra = (*mnger)->extra->extra;
			ft_heapdelone(mng);
		}
		*mnger = (*mnger)->extra;
		if (!mnger || ref == (*mnger))
			break ;
	}
}
