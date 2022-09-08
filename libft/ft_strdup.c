/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:49:34 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/03 11:17:24 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*p;
	char	*s1;
	int		i;

	s1 = (char *)str;
	i = ft_strlen((char *)s1) + 1;
	p = ft_calloc(1, i);
	if (!p)
		return (NULL);
	return (ft_memcpy(p, s1, i));
}
