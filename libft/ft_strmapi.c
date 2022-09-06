/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:05:31 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/03 11:26:24 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mapi;
	t_ptr	ptr;

	ptr = (t_ptr)s;
	i = -1;
	if (!ptr)
		return (NULL);
	mapi = ft_calloc(1 + ft_strlen((char *)ptr), 1);
	if (!mapi)
		return (NULL);
	while (*ptr && (++i || !i))
		mapi[i] = f(i, *ptr++);
	mapi[++i] = '\0';
	return (mapi);
}
