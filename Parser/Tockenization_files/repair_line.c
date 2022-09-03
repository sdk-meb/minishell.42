/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repair_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:39:48 by rel-hach          #+#    #+#             */
/*   Updated: 2022/09/03 11:33:20 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

void	ft_fill_quotes(char *old_line, char *new_line, int *i, int *j)
{
	char	c;

	c = old_line[(*i)];
	new_line[(*j)++] = old_line[(*i)++];
	while (old_line[(*i)] && old_line[(*i)] != c)
		new_line[(*j)++] = old_line[(*i)++];
}

void	ft_add_space_spchar(char *str, char *new, int *i, int *j)
{
	new[(*j)++] = ' ';
	new[(*j)++] = str[(*i)++];
	if (ft_is_special(str[(*i)]))
		new[(*j)++] = str[(*i)++];
	new[(*j)++] = ' ';
}

int	ft_count_special_characters(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_is_special(str[i]))
		{
			count++;
			if (ft_is_redirection(str[i + 1]) && !ft_is_pipe(str[i]))
				i++;
			else if (ft_is_pipe(str[i + 1]))
				return (FAILURE);
		}
		i++;
	}
	return (count);
}

char	*ft_repair_string(char *old_line)
{
	int		count;
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	count = ft_count_special_characters(old_line);
	if (ft_count_special_characters(old_line) == 0)
		return (old_line);
	new_line = ft_calloc(sizeof(char), ft_strlen(old_line) + (count * 2) + 1);
	while (new_line && old_line[i])
	{
		if (ft_is_quote(old_line[i]))
			ft_fill_quotes(old_line, new_line, &i, &j);
		if (ft_is_special(old_line[i]))
			ft_add_space_spchar(old_line, new_line, &i, &j);
		new_line[j++] = old_line[i++];
	}
	new_line[j] = '\0';
	return (new_line);
}
