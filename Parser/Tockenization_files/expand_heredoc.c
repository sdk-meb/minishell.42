/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:24:52 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/31 23:51:31 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

int	count_size_heredoc(char *str)
{
	int	size;
    int i;

	size = 0;
    i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			size = size + ft_strlen(ft_get_env(str, &i));
		}
		else
		{
			i++;
			size++;
		}
	}
	return (size);
}

char	*ft_copy_herdoc(char *str, char *new_str)
{
	int		i;
	int		j;
	char	*env;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '$')
			new_str[j++] = str[i++];
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

char	*ft_expand_heredoc(char *str)
{
	int		size;
	char	*new;

	size = count_size_heredoc(str);
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	new = ft_copy_herdoc(str, new);
	return (free(str), new);
}
