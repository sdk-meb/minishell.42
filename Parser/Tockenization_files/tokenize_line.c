/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:11:49 by rel-hach          #+#    #+#             */
/*   Updated: 2022/09/09 22:04:17 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

int	ft_count_tokens(char *s)
{
	int	count[2];

	count[0] = 0;
	count[1] = 0;
	while (s[count[1]])
	{
		while (s[count[1]] == SPACE)
			count[1]++;
		if (ft_is_quote(s[count[1]]))
		{
			count[1] = ft_get_next_quote(count[1], s);
			while (ft_is_quote(s[count[1] + 1]))
				count[1] = ft_get_next_quote(count[1] + 1, s);
			count[0]++;
			count[1]++;
		}
		else if (s[count[1]] != SPACE && s[count[1]])
			count[0]++;
		while (s[count[1]] != SPACE && s[count[1]])
			if (ft_is_quote(s[count[1]++]))
				count[1] = ft_get_next_quote(count[1] - 1, s) + 1;
	}
	return (count[0]);
}

char	*ft_create_tokens(char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (ft_is_quote(s[i]))
	{
		i = ft_get_next_quote(i, s);
		i++;
	}
	while (s[i] && s[i] != ' ')
	{
		if (ft_is_quote(s[i]))
			i = ft_get_next_quote(i, s);
		i++;
	}
	str = (char *)ft_calloc(sizeof(char), (i + 1));
	if (str)
	{
		ft_strlcpy(str, s, i + 1);
		return (str);
	}
	return (NULL);
}

char	**ft_tokenize_line(char *s)
{
	int		i;
	int		nb_tokens;
	char	**tdstr;

	if (s)
	{
		nb_tokens = ft_count_tokens(s);
		tdstr = (char **)ft_calloc(sizeof(char *), (nb_tokens + 1));
		if (tdstr)
		{
			i = -1;
			while (++i < nb_tokens)
			{
				while (*s == SPACE)
					s++;
				tdstr[i] = ft_create_tokens(s);
				if (!tdstr[i])
					return (NULL);
				s = s + ft_strlen(tdstr[i]);
			}
			tdstr[i] = 0;
			return (tdstr);
		}
	}
	return (NULL);
}
