/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:35:13 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/17 08:07:53 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char*	s;

	s = (char*)str;
	if (!c)
		return ((char *)s + ft_strlen(s));
	while (*s)
		if (*(s++) == (char) c)
			return ((char *)(--s));
	return (NULL);
}
