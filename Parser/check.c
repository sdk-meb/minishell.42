/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:05:20 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/20 17:01:52 by rel-hach         ###   ########.fr       */
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
		printf("minishell : qoutes not closed\n");
	if (error == 4)
		printf("minishell : zsh: parse error near `|'\n");
	if (error == 5)
		printf("minishell : parse error near `<' `>'\n");
	return (FAILURE);
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
			if (str[i] == '|')
				return (FAILURE);
		}
		i++;
	}
	return (0);
}

int	ft_check_consecutive_redirections(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_redirection(str[i]))
		{
			if(str[i + 1] == ' ')
			{
				i++;
				while(str[i] == ' ')
					i++;
				if (ft_is_redirection(str[i]))
					return (FAILURE);
			}
		}
		if (ft_is_redirection(str[i]))
		{
			if (ft_is_redirection(str[i + 1]) && ft_is_redirection(str[i + 2]))
				return (FAILURE);
		}
		if ((str[i] == '>' && str[i + 1] == '<')
			|| (str[i] == '<' && str[i + 1] == '>'))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	ft_check_line(char *line)
{
	int	i;

	i = 0;
	line = ft_strtrim(line, " \t\v");
	if (line[0] == '|' || ft_is_special(line[ft_strlen(line) - 1]))
		return (ft_failure(1));
	if (ft_is_quote(line[0]) && line[1] == ' ')
		return (ft_failure(2));
	if (quotes_are_closed(line))
		return (ft_failure(3));
	if (ft_check_consecutive_pipes_redirections(line))
		return (ft_failure(4));
	if (ft_check_consecutive_redirections(line))
		return (ft_failure(5));
	return (SUCCESS);
}
