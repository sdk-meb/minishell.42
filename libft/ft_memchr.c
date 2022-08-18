/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:55:16 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/18 07:23:05 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	while (len)
	{
		if (*(unsigned char *)s == (unsigned char) c)
			return ((void *)s);
		s++;
		len--;
	}
	return (NULL);
}
