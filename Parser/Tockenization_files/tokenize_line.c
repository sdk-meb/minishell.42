/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:11:49 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/20 16:59:42 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

int	ft_count_tokens(char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		skip_space(s, &i);
		if (ft_is_quote(s[i]))
		{
			while (ft_is_quote(s[i]))
				i = ft_get_next_quote(i++, s);
			count++;
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
	str = (char *)malloc(sizeof(char) * (i + 1));
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
		tdstr = (char **)malloc(sizeof(char *) * (nb_tokens + 1));
		if (tdstr)
		{
			i = -1;
			while (++i < nb_tokens)
			{
				while (*s == SPACE)
					s++;
				tdstr[i] = ft_create_tokens(s);
				if (!tdstr[i])
					return (ft_freestr(tdstr));
				s = s + strlen(tdstr[i]);
			}
			tdstr[i] = 0;
			return (tdstr);
		}
	}
	return (NULL);
}
