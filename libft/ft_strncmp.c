/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:07:22 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/27 21:57:02 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	t_ptr	ptr1;
	t_ptr	ptr2;

	ptr1 = (t_ptr)s1;
	ptr2 = (t_ptr)s2;
	while (n-- && (*ptr1 != '\0' || *ptr2 != '\0'))
	{
		if (*ptr1 != *ptr2)
			return ((unsigned char)*ptr1 - (unsigned char)*ptr2);
		ptr1++;
		ptr2++;
	}
	return (0);
}
