/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:06:30 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/03 07:24:32 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *set, char const *s, int n, int i)
{
	while (set[++i] && s[n])
	{
		if (s[n] == set[i])
		{
			n++;
			i = -1;
		}
	}
	return (n);
}

char	*ft_strtrim(char const *se, char const *set)
{
	int		i;
	int		n;
	char	*s;

	i = -1;
	if (!se)
		return (NULL);
	s = (char *)( se + ft_start(set, se, 0, -1));
	n = ft_strlen((char *)s) - 1;
	while (set[++i] && s[n])
	{
		if (s[n] == set[i])
		{
			n--;
			i = -1;
		}
	}
	return (ft_substr (s, 0, n + 1));
}
