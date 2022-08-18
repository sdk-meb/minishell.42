/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_chap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:02:02 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/18 11:36:48 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_heap	*ft_heapnew(void *dng_ptr, int dangel)
{
	t_heap *con;

	con = (t_heap *)malloc(sizeof(*con));
	if (!con)
		return (NULL);
	con->dng_ptr = dng_ptr;
	con->dangel = dangel;
	con->extra = con;
	return (con);
}

static void	ft_heapadd_front(t_heap **heap, t_heap *new)
{
	t_heap *p;
	t_heap *ref;

	p = (*heap);
	ref = (*heap);
	if (heap && *heap && new)
	{
		while (ref != p->extra)
			p = p->extra;
		new->extra = *heap;
		*heap = new;
		p->extra = *heap;
	}
	else if (heap && !*heap)
		*heap = new;
}

static void	ft_heapdelone(t_heap *heap)
{
	if (!heap)
		return;
	free(heap->dng_ptr);
	free(heap);
}

static void	ft_heapclear(t_heap **heap)
{
	t_heap	*p;

	if (!heap || !*heap)
		return;
	p = *heap;
	*heap = p->extra;
	ft_heapclear(heap);
	ft_heapdelone(p);
}

static t_heap	**governor(t_req ord)
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

static void	c_merge(void *ptr, t_req ord, int dangel)
{
	t_heap **mnger;

	mnger = (t_heap **)governor(ord | _SET | _GET);
	ft_heapadd_front(mnger, ft_heapnew(ptr, dangel));
}

void	c_delete(t_req ord, int dangel)
{
	t_heap	**mnger;
	t_heap	*mng;
	t_heap	*ref;

	mnger = governor(ord & _GET);
	if (!mnger)
		return;
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

void	*new_heap(size_t tcase, t_req ord, int dangel)
{
	void	*ptr;
	if (ord != APPROVED && ord != TEMPORARY)
		return (NULL);
	ptr = ft_calloc(tcase, 1);
	c_merge(ptr, ord, dangel);
	return (ptr);
}
