/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tockenizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:21:56 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/02 15:26:34 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/shell.h"

void	ft_add_space_spchar(char *str, char *new, int *i, int *j)
{
	new[(*j)++] = ' ';
	new[(*j)++] = str[(*i)++];
	if (ft_is_special(str[(*i)]))
		new[(*j)++] = str[(*i)++];
	new[(*j)++] = ' ';
}

bool	ft_is_special(char c)
{
	if (ft_is_pipe(c) && ft_is_parenthesis(c)
		&& ft_is_redirection(c) && ft_is_and(c))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
			if (ft_is_special(str[i + 1]))
				i++;
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
	new_line = malloc(sizeof(char) * ft_strlen(old_line) + (count * 2) + 1);
	if (!new_line)
		return (NULL);
	while (old_line[i])
	{
		if (ft_is_special(old_line[i]))
			ft_add_space_spchar(old_line, new_line, &i, &j);
		else
			new_line[j++] = old_line[i++];
	}
	new_line[j] = '\0';
	return (free (old_line), new_line);
}
