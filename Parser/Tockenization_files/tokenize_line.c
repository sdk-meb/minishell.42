/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:11:49 by rel-hach          #+#    #+#             */
/*   Updated: 2022/09/03 11:38:34 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

// _____________________________________________-

int	ft_count_tokens(char *s)
{
	static int	count;
	static int	i;

	while (s[i])
	{
		while (s[i] == SPACE)
			i++;
		if (ft_is_quote(s[i]))
		{
			i = ft_get_next_quote(i, s);
			while (ft_is_quote(s[i + 1]))
				i = ft_get_next_quote(i + 1, s);
			count++;
			i++;
		}
		else if (s[i] != SPACE && s[i])
			count++;
		while (s[i] != SPACE && s[i])
		{
			if (ft_is_quote(s[i]))
				i = ft_get_next_quote(i, s);
			i++;
		}
	}
	return (count);
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

char	**ft_tokenize_line(char *line)
{
	int		i;
	int		nb_tokens;
	char	**tdstr;
	char	*s;	

	s = line;
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
