/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:49:40 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/23 21:47:07 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	copy_env(char *env, char *new_str, int *j)
{
	while (*env)
	{
		new_str[(*j)++] = *env;
		env++;
	}
}

char	*ft_get_env(char *str, int *i)
{
	int		j;
	char	temp[1000];
	char	*env;

	j = 0;
	while (str[(*i)] && str[(*i)] != ' ' && !ft_is_quote(str[(*i)])
		&& str[(*i)] != '$')
		temp[j++] = str[(*i)++];
	temp[j] = '\0';
	env = get_env(temp);
	return (env);
}

int	count_dq_case(char *str, int *i)
{
	int	size;

	size = 0;
	(*i)++;
	while (str[(*i)] && str[(*i)] != '\"')
	{
		if (str[(*i)] == '$')
		{
			(*i)++;
			size = size + ft_strlen(ft_get_env(str, i));
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
	while (str[(*i)] != '\'')
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
		if ((str[i]) == '$')
		{
			i++;
			size += ft_strlen(ft_get_env(str, &i));
		}
		if (str[i] != '$' && !ft_is_quote(str[i]))
		{
			i++;
			size++;
		}
	}
	return (size);
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
			(*i)++;
			env = ft_get_env(str, i);
			if (env)
				copy_env(env, new, j);
		}
	}
	(*i)++;
}

char	*ft_copy(char *str, char *new_str)
{
	int		i;
	int		j;
	char	*env;

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
		{
			i++;
			env = ft_get_env(str, &i);
			if (env)
				copy_env(env, new_str, &j);
		}
	}
	new_str[j] = '\0';
	return (new_str);
}

char	*ft_expand(char *str)
{
	int		size;
	char	*new;

	size = count_size(str);
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	new = ft_copy(str, new);
	return (new);
}
