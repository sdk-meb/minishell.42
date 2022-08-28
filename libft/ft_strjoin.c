/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:04:30 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/27 22:11:20 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *ss1, char const *ss2)
{
	int		i;
	char	*join;
	t_ptr	s1;
	t_ptr	s2;

	s1 = (t_ptr)ss1;
	s2 = (t_ptr)ss2;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	join = malloc (1 + i);
	if (!join)
		return (NULL);
	join[i] = '\0';
	while (*s1)
		*join++ = *(t_ptr)s1++;
	while (*s2)
		*join++ = *(t_ptr)s2++;
	return (join -= i);
}
