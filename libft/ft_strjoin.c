/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:04:30 by mes-sadk          #+#    #+#             */
/*   Updated: 2021/11/22 20:04:30 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	join = malloc (1 + i);
	if (!join)
		return (NULL);
	join[i] = '\0';
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	return (join -= i);
}
