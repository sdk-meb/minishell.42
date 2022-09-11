/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:05:49 by rel-hach          #+#    #+#             */
/*   Updated: 2022/09/10 10:53:56 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

int	count_dq_case(char *str, int *i)
{
	int	size;

	size = 0;
	(*i)++;
	while (str[(*i)] && str[(*i)] != '\"')
	{
		if (str[(*i)] == '$' && str[(*i) + 1] != '\"')
		{
			if (ft_isdigit(str[(*i) + 1]) == 0)
				*i = *i + 2;
			else
			{
				(*i)++;
				size = size + ft_strlen(ft_get_env(str, i));
			}
		}
		else
		{
			(*i)++;
			size++;
		}
	}
	(*i)++;
	return (size);
}

int	count_sq_case(char *str, int *i)
{
	int	size;

	size = 0;
	(*i)++;
	while (str[(*i)] && str[(*i)] != '\'')
	{
		(*i)++;
		size++;
	}
	(*i)++;
	return (size);
}

int	count_size(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			size = count_sq_case(str, &i) + size;
		if (str[i] == '\"')
			size = count_dq_case(str, &i) + size;
		if ((str[i]) == '$' && str[i + 1] != '\0')
		{
			i++;
			size += ft_strlen(ft_get_env(str, &i));
		}
		if ((str[i] != '$' && !ft_is_quote(str[i]))
			|| (str[i] == '$' && str[i + 1] == '\0'))
		{
			i++;
			size++;
		}
	}
	return (size);
}

int	is_spc(char c)
{
	if (c == '~' || c == '#' || c == '$')
		return (1);
	if (c == '*' || c == '.' || c == ',')
		return (1);
	if (c == '!' || c == '^' || c == '-')
		return (1);
	if (c == '=' || c == '+')
		return (1);
	if (c == ':' || c == '@' || c == '\"')
		return (1);
	if (c == '\'' || c == ' ')
		return (1);
	return (0);
}
