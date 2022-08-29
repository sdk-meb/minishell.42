/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:58:31 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/29 16:44:51 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnstr2(t_ptr haystack, t_ptr needle, size_t len)
{
	int	i;

	i = 0;
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

char	*ft_strnstr(char *haystack, const char *needle, size_t len)
{
	t_ptr	hay;
	t_ptr	ned;

	hay = (t_ptr)haystack;
	ned = (t_ptr)needle;
	if (!*needle)
		return (haystack);
	return (ft_strnstr2(hay, ned, len));
}
