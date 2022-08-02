/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:02:05 by mes-sadk          #+#    #+#             */
/*   Updated: 2021/11/22 20:02:27 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (start > n)
		n = 0;
	else if (len + start > n)
		n = n - start;
	else
		n = len;
	sub = malloc(n + 1);
	if (!sub)
		return (NULL);
	sub[n] = '\0';
	while (n-- > 0)
		sub[n] = s[start + n];
	return (sub);
}
