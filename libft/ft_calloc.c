/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:17:23 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/03 16:50:33 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_req	genus(t_req ord)
{
	static t_req	o_ord;

	if (ord == EMPTY)
		return (o_ord);
	o_ord = ord;
	return (ord);
}	

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	char	*r;

	if (genus(EMPTY) == 0)
		genus(TEMPORARY);
	p = new_heap(count * size, genus(EMPTY), EMPTY);
	if (!p)
		return (NULL);
	r = p;
	ft_bzero(r, count * size);
	return ((void *)r);
}
