/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:24:28 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/02 12:54:40 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/shell.h"

bool ft_is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

bool ft_is_pipe(char c)
{
	if (c == '|')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

bool ft_is_parenthesis(char c)
{
	if (c == '(' || c == ')')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

bool ft_is_and(char c)
{
	if (c == '&')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

bool ft_is_redirection(char c)
{
	if (c == '>' || c == '<')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

bool ft_is_operator(_str	str)
{
	if (!ft_memcmp(str, "||", 3) || !ft_memcmp(str, "&&", 3))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
