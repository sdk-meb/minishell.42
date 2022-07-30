/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tockens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:19:40 by rel-hach          #+#    #+#             */
/*   Updated: 2022/07/27 14:54:55 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (strlen(src));
}

int	ft_is_special(char c)
{
	if (!ft_is_pipe(c) && !ft_is_parenthesis(c)
		&& !ft_is_redirection(c) && !ft_is_and(c))
		return (0);
	return (1);
}

// int	count_special_characters(char *str)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		if (ft_is_special(str[i]))
// 		{
// 			count++;
// 			if (ft_is_special(str[i + 1]))
// 				i++;
// 		}
// 		i++;
// 	}
// 	return (count);
// }

void	ft_add_space_spchar(char *str, char *new, int *i, int *j)
{
	new[(*j)++] = ' ';
	new[(*j)++] = str[(*i)++];
	if (ft_is_special(str[(*i)]))
		new[(*j)++] = str[(*i)++];
	new[(*j)++] = ' ';
}
