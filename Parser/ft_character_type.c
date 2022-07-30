/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:24:28 by rel-hach          #+#    #+#             */
/*   Updated: 2022/07/24 19:16:49 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	else
		return (0);
}

int	ft_is_pipe(char c)
{
	if (c == '|')
		return (1);
	else
		return (0);
}

int	ft_is_parenthesis(char c)
{
	if (c == '(' || c == ')')
		return (1);
	else
		return (0);
}

int	ft_is_and(char c)
{
	if (c == '&')
		return (1);
	return (0);
}

int	ft_is_redirection(char c)
{
	if (c == '>' || c == '<')
		return (1);
	else
		return (0);
}

int	ft_is_operator(char *str)
{
	if (!ft_strcmp(str, "||") || !ft_strcmp(str, "&&"))
		return (1);
	return (0);
}
