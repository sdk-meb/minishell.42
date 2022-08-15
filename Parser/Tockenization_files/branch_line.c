/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:11:49 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/15 09:59:45 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

int	ft_get_next_quote(int i, char *line)
{
	char	quote_type;

	quote_type = line[i++];
	while (line[i] && line[i] != quote_type)
		i++;
	return (i);
}

int	ft_calculate_words(char *line, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] == c)
			i++;
		if (ft_is_quote(line[i]))
		{
			i = ft_get_next_quote(i, line);
			while (ft_is_quote(line[i + 1]))
				i = ft_get_next_quote(i + 1, line);
			count++;
			i++;
		}
		else if (line[i] != c && line[i])
			count++;
		while (line[i] != c && line[i])
		{
			if (ft_is_quote(line[i]))
				i = ft_get_next_quote(i, line);
			i++;
		}
	}
	return (count);
}

char	*ft_allocate_fill_str(char *line, char c)
{
	int		i;
	char	*str;

	i = 0;
	if (ft_is_quote(line[i]))
	{
		i = ft_get_next_quote(i, line);
		while (ft_is_quote(line[i + 1]))
			i = ft_get_next_quote(i + 1, line);
		i++;
	}
	while (line[i] && line[i] != c)
	{
		if (ft_is_quote(line[i]))
			i = ft_get_next_quote(i, line);
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str)
	{
		ft_strlcpy(str, line, i + 1);
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

char	**ft_branch_line(char *line, char c)
{
	int		i;
	int		nb_words;
	char	**tdstr;

	if (line)
	{
		nb_words = ft_calculate_words(line, c);
		tdstr = (char **)malloc(sizeof(char *) * (nb_words + 1));
		if (!tdstr)
			return (NULL);
		i = -1;
		while (++i < nb_words)
		{
			while (*line == c)
				line++;
			tdstr[i] = ft_allocate_fill_str(line, c);
			if (!tdstr[i])
				return (ft_freestr(tdstr));
			line = line + strlen(tdstr[i]);
		}
		tdstr[i] = 0;
		return (tdstr);
	}
	return (NULL);
}
