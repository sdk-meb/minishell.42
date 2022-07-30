/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:13:59 by mes-sadk          #+#    #+#             */
/*   Updated: 2021/11/20 17:17:07 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (!dstsize)
		return (ft_strlen(src));
	while (*s && --dstsize)
		*d++ = *s++;
	*d = '\0';
	return (ft_strlen(src));
}
