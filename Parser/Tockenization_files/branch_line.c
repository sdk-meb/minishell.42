/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:11:49 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/13 13:22:10 by rel-hach         ###   ########.fr       */
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
	static int	i;
	static int	count;

	while (line[i])
	{
		while (line[i] == c)
			i++;
		if (ft_is_quote(line[i]))
		{
			i = ft_get_next_quote(i, line);
			while (ft_is_quote(line[i + 1]))
				i = ft_get_next_quote(i, line);
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
	char	*token;

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
	token = (char *)malloc(sizeof(char) * (i + 1));
	if (token)
	{
		ft_strlcpy(token, line, i + 1);
		return (token);
	}
	return (NULL);
}

char	**ft_free_strings(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i++])
		free(ptr[i]);
	free(ptr);
	return (NULL);
}

char	**ft_branch_line(char *line, char c)
{
	int		i;
	int		words_nb;
	char	**ptr;

	if (line)
	{
		words_nb = ft_calculate_words(line, c);
		ptr = (char **)malloc(sizeof(char *) * (words_nb + 1));
		if (!ptr)
			return ((void *)0);
		i = 0;
		while (i++ < words_nb)
		{
			while (*line == c)
				line++;
			ptr[i] = ft_allocate_fill_str(line, c);
			if (!ptr)
				return (ft_free_strings(ptr));
			line = line + ft_strlen(ptr[i]);
		}	
		ptr[i] = 0;
		return (ptr);
	}
	return (NULL);
}
