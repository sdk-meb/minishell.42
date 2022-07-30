/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:49:34 by mes-sadk          #+#    #+#             */
/*   Updated: 2021/11/22 14:41:44 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	i = ft_strlen((char *)s1) + 1;
	p = malloc(i);
	if (!p)
		return (NULL);
	return (ft_memcpy(p, s1, i));
}
