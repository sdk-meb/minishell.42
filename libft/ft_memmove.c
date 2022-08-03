/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:16:30 by mes-sadk          #+#    #+#             */
/*   Updated: 2021/11/22 19:31:59 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && ! src)
		return (NULL);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (len-- > 0)
		*((char *)dst + len) = *((char *)src + len);
	return (dst);
}
