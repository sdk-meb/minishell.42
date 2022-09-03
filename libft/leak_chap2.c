/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_chap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 00:24:18 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/03 17:51:19 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_heapclear(t_heap **heap)
{
	t_heap *ptr;
	t_heap	*fre;

	if (!heap)
		return ;
	ptr = (*heap);
	while (ptr)
	{
		fre = ptr;
		ptr = ptr->extra;
		free(fre->dng_ptr);
		free(fre);
	}
	free((void *)heap);
}

t_heap	**governor(t_req ord)
{
	static t_heap	**glb;
	static t_heap	**tmp;

	if (ord == EMPTY)
		tmp = NULL;
	if (ord == TEMPORARY && tmp)
		return (tmp);
	else if (ord == APPROVED && glb)
		return (glb);
	else if (ord  == APPROVED)
	{
		glb = (t_heap **)malloc(sizeof(glb));
		if (!glb)
			return (perror("malloc :"), NULL);
		*glb = NULL;
		return (glb);
	}
	else if (ord == TEMPORARY)
	{
		tmp = (t_heap **)malloc(sizeof(tmp));
		if (!tmp)
			return (perror("malloc :"), NULL);
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

	mnger = governor(ord);
	if (!mnger)
		return ;
	if (dangel < 0)
	{
		ft_heapclear(mnger);
		if (ord == TEMPORARY)
			governor(EMPTY);
		return ;
	}
	ref = (*mnger);
	while (0 && mnger && *mnger)
	{
		if ((*mnger)->extra->dangel == dangel)
		{
			mng = (*mnger)->extra;
			(*mnger)->extra = (*mnger)->extra->extra;
			free(mng->dng_ptr);
			free(mng);
		}
		*mnger = (*mnger)->extra;
		if (!mnger || ref == (*mnger))
			break ;
	}
}
