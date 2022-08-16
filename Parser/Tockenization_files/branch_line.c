/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:11:49 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/16 13:35:49 by rel-hach         ###   ########.fr       */
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

void	ft_skip_space(char *str, int *i)
{
	while (str[(*i)] == ' ')
		(*i)++;
}

int	ft_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		ft_skip_space(str, &i);
		if (ft_is_quote(str[i]))
		{
			i = ft_get_next_quote(i, str);
			count++;
			while (ft_is_quote(str[i + 1]))
			{
				i = ft_get_next_quote(++i, str);
				count++;
			}
		}
		else if (str[i] != ' ' && !ft_is_quote(str[i - 1]))
			count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
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

char	*ft_allocate_fill_str(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (ft_is_quote(line[i]))
	{
		i = ft_get_next_quote(i, line);
		i++;
	}
	else
		while (line[i] && line[i] != ' ' && !ft_is_quote(line[i]))
			i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str)
	{
		ft_strlcpy(str, line, i + 1);
		return (str);
	}
	return (NULL);
}

char	**ft_branch_line(char *line, char c)
{
	int		i;
	int		nb_words;
	char	**tdstr;

	if (line)
	{
		nb_words = ft_words(line);
		tdstr = (char **)malloc(sizeof(char *) * (nb_words + 1));
		if (!tdstr)
			return (NULL);
		i = -1;
		while (++i < nb_words)
		{
			while (*line == c)
				line++;
			tdstr[i] = ft_allocate_fill_str(line);
			if (!tdstr[i])
				return (ft_freestr(tdstr));
			line = line + ft_strlen(tdstr[i]);
		}
		tdstr[i] = 0;
		return (tdstr);
	}
	return (NULL);
}
