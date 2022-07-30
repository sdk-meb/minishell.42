/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:58:31 by mes-sadk          #+#    #+#             */
/*   Updated: 2021/11/20 17:21:18 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(char *haystack, const char *needle, size_t len)
{
	int	i;

	i = 0;
	if (!*needle)
		return (haystack);
	while (len-- && *haystack)
	{
		if (*(haystack++) - *needle)
		{
			haystack -= i;
			needle -= i;
			len += i;
			i = -1;
		}
		else
			needle++;
		i++;
		if (!*needle)
			return (haystack - i);
	}
	return (NULL);
}
