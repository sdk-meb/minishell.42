/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:05:20 by rel-hach          #+#    #+#             */
/*   Updated: 2022/09/10 19:26:10 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_check_line(char *line)
{
	line = ft_strtrim(line, " \t\v");
	if (line[0] == '|' || ft_is_special(line[ft_strlen(line) - 1]))
		ft_err("minishell : parse error near `|'", EMPTY);
	else if (quotes_are_closed(line))
		ft_err("minishell : qoutes not closed", EMPTY);
	else if (ft_check_consecutive_pipes_redirections(line))
		ft_err("minishell : parse error near `|'", EMPTY);
	else if (ft_redirection_error(line))
		ft_err("minishell : parse error near `<' `>'", EMPTY);
	else
		return (SUCCESS);
	return (FAILURE);
}
