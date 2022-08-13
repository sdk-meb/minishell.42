/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:49:40 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/13 12:57:31 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Include/minishell.h"

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
	while (str[j] && str[j] != ' ' && str[j] != '$' && str[j] != '\"')
		j++;
	env = malloc(sizeof(char) * (j + 1));
	if (!env)
		return (NULL);
	(*len) = (*len) + j + 1;
	while (i < j)
	{
		env[i] = str[i];
		i++;
	}
	env[i] = '\0';
	new = getenv(env);
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
	while (str[j] && str[j] != ' ' && str[j] != '$' && str[j] != '\"')
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
	if (str[(*i)] == '\'' || str[(*i)] == '\"')
			(*i)++;
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
		skip_quote(str, &i);
		if (str[i] == '$' && !check_if_single_quotes(str, i))
		{
			env = get_env_t(&str[++i], &i);
			copy_env(env, new_str, &j);
		}
		skip_quote(str, &i);
		new_str[j++] = str[i++];
	}
	new_str[j] = '\0';
}

char	*calculate_dollars_signs(char *str)
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

