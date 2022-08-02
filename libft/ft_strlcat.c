/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:47:47 by mes-sadk          #+#    #+#             */
/*   Updated: 2021/11/24 20:07:27 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *s, size_t size)
{
	size_t	sd;
	size_t	return_val;
	size_t	ss;
	size_t	i;

	sd = ft_strlen(dst);
	ss = ft_strlen(s);
	i = 0;
	if (size > sd)
		return_val = sd + ss;
	else
		return_val = ss + size;
	while (s[i] && (sd + 1) < size)
	{
		dst[sd++] = s[i++];
	}
	dst[sd] = '\0';
	return (return_val);
}
