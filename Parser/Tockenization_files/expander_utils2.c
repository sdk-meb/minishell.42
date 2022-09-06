/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:06:05 by rel-hach          #+#    #+#             */
/*   Updated: 2022/09/06 10:29:36 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

void	copy_env(char *env, char *new_str, int *j)
{
	while (*env)
	{
		new_str[(*j)++] = *env;
		env++;
	}
}

void	ft_copy_sq_case(char *str, char *new, int *i, int *j)
{
	(*i)++;
	while (str[(*i)] && str[(*i)] != '\'')
		new[(*j)++] = str[(*i)++];
	(*i)++;
}

void	ft_copy_dq_case(char *str, char *new, int *i, int *j)
{
	char	*env;

	(*i)++;
	while (str[(*i)] && str[(*i)] != '\"')
	{
		if (str[(*i)] != '$')
			new[(*j)++] = str[(*i)++];
		if (str[(*i)] == '$')
		{
			if (str[(*i) + 1] == '\"')
				new[(*j)++] = str[(*i)++];
			else if (ft_isdigit(str[(*i) + 1]) == 0)
				*i = *i + 2;
			else
			{
				(*i)++;
				env = ft_get_env(str, i);
				if (env)
					copy_env(env, new, j);
			}
		}
	}
	(*i)++;
}

void	ft_dollar_case(char *str, char *new_str, int *i, int *j)
{
	char	*env;

	if (ft_isdigit(str[(*i) + 1]) == 0)
		(*i) = (*i) + 2;
	else if (str[(*i) + 1] == '\0')
	{
		new_str[(*j)++] = str[(*i)++];
		new_str[(*j)] = '\0';
	}
	else
	{
		(*i)++;
		env = ft_get_env(str, i);
		if (env)
			copy_env(env, new_str, j);
	}
}

char	*ft_copy(char *str, char *new_str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_is_quote(str[i]) && str[i] != '$')
			new_str[j++] = str[i++];
		if (str[i] == '\'')
			ft_copy_sq_case(str, new_str, &i, &j);
		if (str[i] == '\"')
			ft_copy_dq_case(str, new_str, &i, &j);
		if (str[i] == '$')
			ft_dollar_case(str, new_str, &i, &j);
	}
	new_str[j] = '\0';
    return (new_str);
}
