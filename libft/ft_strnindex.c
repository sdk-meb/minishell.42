/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnindex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:59:40 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/24 00:11:43 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnindex(const void *s, int c, int len)
{
	int	i;

	i = -1;
	while (i++ < len && s && *(unsigned char *)s)
	{
		if (*(unsigned char *)s == (unsigned char) c)
			return (i);
		s++;
	}
	return (-1);
}
