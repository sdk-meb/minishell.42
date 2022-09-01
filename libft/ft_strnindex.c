/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnindex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:59:40 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/27 22:54:30 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnindex(const void *s, int c, int len)
{
	int		i;
	t_ptr	ptr;

	ptr = (t_ptr)s;
	i = 0;
	while (i++ < len && ptr && *(unsigned char *)ptr)
	{
		if (*(unsigned char *)ptr == (unsigned char) c)
			return (i);
		ptr++;
	}
	return (0);
}
