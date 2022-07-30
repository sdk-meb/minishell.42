/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:05:31 by mes-sadk          #+#    #+#             */
/*   Updated: 2021/11/22 20:14:26 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mapi;

	i = -1;
	if (!s)
		return (NULL);
	mapi = malloc(1 + ft_strlen((char *)s));
	if (!mapi)
		return (NULL);
	while (*s && (++i || !i))
		mapi[i] = f(i, *s++);
	mapi[++i] = '\0';
	return (mapi);
}
