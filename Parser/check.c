/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:05:20 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/16 15:30:39 by rel-hach         ###   ########.fr       */
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

int	ft_failure(int error)
{
	if (error == 1)
		printf("minishell: parse error near `|'\n");
	if (error == 2)
		printf("minishell: command not found\n");
	if (error == 3)
		printf("qoutes not closed\n");
	return (FAILURE);
}

int	ft_check_line(char *line)
{
	int	i;

	i = 0;
	line = ft_strtrim(line, " \t\v");
	if (line[0] == '|' || line[ft_strlen(line) - 1] == '|')
		return (ft_failure(1));
	if (ft_is_quote(line[0]) && line[1] == ' ')
		return (ft_failure(2));
	if (quotes_are_closed(line))
		return (ft_failure(3));
	return (SUCCESS);
}
