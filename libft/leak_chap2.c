/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_chap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 00:24:18 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/05 22:33:05 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_heapclear(t_heap **heap)
{
	t_heap	*ptr;
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
	static t_heap	**glb[2];
	int				style;

	if (ord == TEMPORARY && glb[1])
		return (glb[1]);
	style = 1;
	if (ord == APPROVED && glb[0])
		return (glb[0]);
	if ((ord == TEMPORARY && !glb[1]) || (ord == APPROVED && !glb[0]))
	{
		if (ord == APPROVED)
			style = 0;
		glb[style] = (t_heap **)malloc(sizeof(glb[style]));
		if (!glb[style])
			return (perror("malloc :"), NULL);
		*glb[style] = NULL;
		return (glb[style]);
	}
	if (ord == EMPTY)
		glb[1] = NULL;
	return (NULL);
}

void	c_delete(t_req ord, int dangel)
{
	t_heap	**mnger;

	mnger = governor(ord);
	if (dangel < 0)
		ft_heapclear(mnger);
	if (dangel < 0 && ord == TEMPORARY)
		governor(EMPTY);
}
