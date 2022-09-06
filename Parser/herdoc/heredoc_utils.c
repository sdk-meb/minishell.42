/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:19:47 by rel-hach          #+#    #+#             */
/*   Updated: 2022/09/06 11:22:03 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

char	*copy_new_delim(char *delim, char *new_delim)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (delim[i])
	{
		if (ft_is_quote(delim[i]))
		{
			c = delim[i++];
			while (delim[i] && delim[i] != c)
				new_delim[j++] = delim[i++];
			i++;
		}
		else if (!ft_is_quote(delim[i]))
			new_delim[j++] = delim[i++];
	}
	return (new_delim);
}

char	*ft_allocate (int size)
{
	char	*new;

	new = (char *)ft_calloc(sizeof(char), (size + 1));
	if (!new)
		return (NULL);
	return (new);
}

int	quotes_is_there(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_quote(str[i]))
			return (1);
		i++;
	}
	return (0);
}