/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:05:20 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/13 21:07:59 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

bool	quotes_are_closed(char *line)
{
	int		i;
	char	type_quote;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '\'' || line[i] == '\"'))
		{
			type_quote = line[i++];
			while (line[i] && line[i] != type_quote)
				i++;
			if (!line[i])
				return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_check_line(char *line)
{
	int	i;

	i = 0;
	line = ft_strtrim(line, " \t\v");
	if (line[0] == '|' || line[ft_strlen(line - 1)] == '|')
		return (FAILURE);
	if (quotes_are_closed(line))
		return (FAILURE);
	return (SUCCESS);
}
