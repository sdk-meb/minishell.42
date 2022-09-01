/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:55:16 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/27 21:46:49 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	t_ptr	p;

	p = (t_ptr)s;
	while (len)
	{
		if (*(unsigned char *)p == (unsigned char) c)
			return ((void *)p);
		p++;
		len--;
	}
	return (NULL);
}
