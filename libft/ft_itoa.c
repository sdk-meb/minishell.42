/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:23:03 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/03 11:18:58 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(unsigned int i)
{
	int	t;

	t = 0;
	while (++t && i)
		i = i / 10;
	return (t);
}

char	*ft_itoa(int i)
{
	unsigned int	m;
	int				s;
	char			*a;

	m = i;
	if (i < 0)
		m = i * (-1);
	s = ft_len(m);
	if (i <= 0)
		a = ft_calloc(s + 1, 1);
	else
		a = ft_calloc(s--, 1);
	if (!a)
		return (NULL);
	a[0] = '-';
	a[s] = '\0';
	while ((s && m) || !i++)
	{
		a[--s] = (m % 10) + 48;
		m = m / 10;
	}
	return (a);
}
