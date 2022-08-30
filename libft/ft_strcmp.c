/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:04:44 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/30 08:48:42 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *ss1, const char *ss2)
{
	char	*s1;
	char	*s2;

	s1 = (char *)ss1;
	s2 = (char *)ss2;
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}
