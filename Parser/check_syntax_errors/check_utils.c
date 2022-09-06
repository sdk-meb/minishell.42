/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:52:08 by rel-hach          #+#    #+#             */
/*   Updated: 2022/09/06 14:33:43 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

int	quotes_are_closed(char *line)
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

int	ft_check_consecutive_pipes_redirections(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
		{
			while (str[++i] == ' ')
				i++;
			if (str[i] == '|' || ft_is_redirection(str[i]))
				return (FAILURE);
		}
		i++;
	}
	return (0);
}

void	ft_skip(char *str, int *i)
{
	(*i)++;
	while (str[(*i)] == ' ')
		(*i)++;
}

int	ft_redirection_error(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
	{
		if (ft_is_redirection(str[i]) && str[i + 1] == ' ')
		{
			ft_skip(str, &i);
			if (ft_is_redirection(str[i]))
				return (FAILURE);
		}
		if (ft_is_redirection(str[i]) && ft_is_redirection(str[i + 1])
			&& ft_is_redirection(str[i + 2]))
			return (FAILURE);
		if ((str[i] == '>' && str[i + 1] == '<')
			|| (str[i] == '<' && str[i + 1] == '>'))
			return (FAILURE);
	}
	return (SUCCESS);
}

int	and(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '&' && ft_is_special(str[i + 1]))
			return (FAILURE);
		else if (ft_is_special(str[i] && str[i + 1] == '&'))
			return (FAILURE);
	}
	return (SUCCESS);
}
