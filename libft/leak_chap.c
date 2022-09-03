/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_chap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:02:02 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/03 17:11:19 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_heap	*ft_heap_new(void *dng_ptr, int dangel)
{
	t_heap	*con;

	con = (t_heap *)malloc(sizeof(*con));
	if (!con)
		return (perror("malloc :"), NULL);
	con->dng_ptr = dng_ptr;
	con->dangel = dangel;
	con->extra = NULL;
	return (con);
}

static void	ft_heap_add(t_heap **heap, t_heap *new)
{
	t_heap	*p;

	if (!heap)
		return ;
	if (*heap && new)
	{
		p = (*heap)->extra;
		(*heap)->extra = new;
		new->extra = p;
	}
	else if (heap && !*heap)
		*heap = new;
//	for(int i = 1 ; i< 500; i+=5){free(ft_memset(malloc(i), i, 45));}
//	printf("_mer_____ %p--->%p ++%d++\n", new->dng_ptr,new,genus(EMPTY));
}

static void	c_merge(void *ptr, t_req ord, int dangel)
{
	t_heap	**mnger;

	mnger = (t_heap **)governor(ord);
	ft_heap_add(mnger, ft_heap_new(ptr, dangel));
}

void	*new_heap(size_t tcase, t_req ord, int dangel)
{
	void	*ptr;

	if (ord != APPROVED && ord != TEMPORARY)
		return (NULL);
	ptr = malloc(tcase);
	if (!ptr)
	{
		perror("malloc :");
		return (NULL);
	}
	c_merge(ptr, ord, dangel);
	return (ptr);
}
