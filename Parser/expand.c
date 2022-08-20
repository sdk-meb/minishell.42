/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:49:40 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/20 18:58:22 by mes-sadk         ###   ########.fr       */
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

void	skip_quote(char *str, int *i)
{
	while (str[(*i)] == '\"')
			(*i)++;
}

char	*get_env_t(char *str, int *len)
{
	char	*env;
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] && str[j] != ' ' && str[j] != '$' && !ft_is_quote(str[j]))
		j++;
	env = malloc(sizeof(char) * (j + 1));
	if (!env)
		return (NULL);
	while (i < j)
	{
		env[i] = str[i];
		i++;
		(*len)++;
	}
	env[i] = '\0';
	new = _get_env(env);
	return (free(env), new);
}

void	ft_copy(char *new_str, char *str)
{
	char	*env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		skip_quote(str, &i);
		if (str[i] != '$')
			new_str[j++] = str[i++];
		if (str[i] == '$')
		{
			env = get_env_t(&str[++i], &i);
			if (env)
				copy_env(env, new_str, &j);
		}
	}
	new_str[j] = '\0';
}

char	*get_env(char *str, int *len)
{
	char	*env;
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] && str[j] != ' ' && str[j] != '$' && !ft_is_quote(str[j]))
		j++;
	env = malloc(sizeof(char) * (j + 1));
	if (!env)
		return (NULL);
	while (i < j)
	{
		env[i] = str[i];
		i++;
	}
	env[i] = '\0';
	new = getenv(env);
	(*len) = (*len) + j + 1;
	return (free(env), new);
}

char	*ft_sq_case(char *str)
{
	int		i;
	int		j;
	int		s;
	char	*new;

	i = -1;
	j = 0;
	s = 0;
	while (str[++i])
	{
		if (str[i] == '\'')
			s++;
	}
	new = malloc(sizeof(char) * (ft_strlen(str) - s + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		while (str[i] == '\'')
			i++;
		new[j++] = str[i++];
	}
	new[j] = '\0';
	return (new);
}

char	*ft_expand(char *str)
{
	int		i;
	char	*new;
	int		minus;
	int		size;

	i = -1;
	minus = 0;
	size = 0;
	if (str[0] == '\'')
		return (ft_sq_case(str));
	while (str[++i])
	{
		if (str[i] == '$')
			size = ft_strlen(get_env(&str[++i], &minus)) + size;
	}
	new = malloc(sizeof(char) * ft_strlen (str) + (size - minus) + 1);
	if (!new)
		return (NULL);
	ft_copy(new, str);
	return (new);
}
