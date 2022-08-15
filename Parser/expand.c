/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:49:40 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/15 10:01:56 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

int	check_if_single_quotes(char *str, int i)
{
	int	j;
	int	left;
	int	right;

	j = i;
	left = 0;
	right = 0;
	while (str[i] && str[i] != '\"')
	{
		if (str[i] == '\'')
			left++;
		i--;
	}
	while (str[j] && str[j] != '\"')
	{
		if (str[j] == '\'')
			right++;
		j++;
	}
	if (left == 0 || right == 0)
		return (0);
	if (left % 2 == 0 && right % 2 == 0)
		return (0);
	return (1);
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
	new = getenv(env);
	return (free(env), new);
}

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
	while (str[(*i)] == '\'' || str[(*i)] == '\"')
			(*i)++;
}

void	skip_dquote(char *str, int *i)
{
	while (str[(*i)] == '\"')
			(*i)++;
}

void	ft_copy(char *str, char *new_str, int *i, int *j)
{
	char	*env;

	skip_dquote(str, i);
	while (str[(*i)] != '\"')
	{
		if (str[(*i)] == '$')
		{
			env = get_env_t(&str[++(*i)], i);
			if (env)
				copy_env(env, new_str, j);
		}	
		new_str[(*j)++] = str[(*i)++];
	}
	skip_dquote(str, i);
}

void	copy(char *new_str, char *str)
{
	char	*env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			ft_copy(str, new_str, &i, &j);
		skip_quote(str, &i);
		if (str[i] != '$')
			new_str[j++] = str[i++];
		if (str[i] == '$' && !check_if_single_quotes(str, i))
		{
			env = get_env_t(&str[++i], &i);
			if (env)
				copy_env(env, new_str, &j);
		}
		if (str[i] == '$' && check_if_single_quotes(str, i))
			new_str[j++] = str[i++];
	}
	new_str[j] = '\0';
}

char	*ft_expand(char *str)
{
	int			i;
	int			size;
	int			minus;
	char		*new_str;

	i = 0;
	minus = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '$' && !check_if_single_quotes(str, i))
			size = ft_strlen(get_env(&str[++i], &minus)) + size;
		i++;
	}
	new_str = malloc(sizeof(char) * ft_strlen (str) + (size - minus) + 1);
	if (!new_str)
		return (NULL);
	copy(new_str, str);
	return (new_str);
}
