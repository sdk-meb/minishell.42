/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_chap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:02:02 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/27 22:08:30 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_heap	*ft_heapnew(void *dng_ptr, int dangel)
{
	t_heap	*con;

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
	t_heap	*p;
	t_heap	*ref;

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

void	c_merge(void *ptr, t_req ord, int dangel)
{
	t_heap	**mnger;

	mnger = (t_heap **)governor(ord | _SET | _GET);
	ft_heapadd_front(mnger, ft_heapnew(ptr, dangel));
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