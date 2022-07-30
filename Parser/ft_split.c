/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:05:49 by rel-hach          #+#    #+#             */
/*   Updated: 2022/07/23 19:16:24 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_get_next_quote(int i, char *line)
{
	char	quote_type;

	quote_type = line[i++];
	while (line[i] && line[i] != quote_type)
		i++;
	return (i);
}

int	ft_wordscounter(char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (ft_is_quote(s[i]))
		{
			i = ft_get_next_quote(i, s);
			while (ft_is_quote(s[i + 1]))
				i = ft_get_next_quote(i + 1, s);
			count++;
			i++;
		}
		else if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
		{
			if (ft_is_quote(s[i]))
				i = ft_get_next_quote(i, s);
			i++;
		}
	}
	return (count);
}

char	*ft_write_words(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	if (ft_is_quote(s[i]))
	{
		i = ft_get_next_quote(i, s);
		while (ft_is_quote(s[i + 1]))
			i = ft_get_next_quote(i + 1, s);
		i++;
	}
	while (s[i] && s[i] != c)
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

static char	**ft_freestr(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free (tab);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		nb_words;
	char	**tdstr;

	if (s)
	{
		nb_words = ft_wordscounter(s, c);
		tdstr = (char **)malloc(sizeof(char *) * (nb_words + 1));
		if (!tdstr)
			return (NULL);
		i = -1;
		while (++i < nb_words)
		{
			while (*s == c)
				s++;
			tdstr[i] = ft_write_words(s, c);
			if (!tdstr[i])
				return (ft_freestr(tdstr));
			s = s + strlen(tdstr[i]);
		}
		tdstr[i] = 0;
		return (tdstr);
	}
	return (NULL);
}
