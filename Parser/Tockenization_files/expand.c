/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:49:40 by rel-hach          #+#    #+#             */
/*   Updated: 2022/09/10 19:28:58 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

char	*count_size_and_allocate(char *str, int i)
{
	char	*new;
	int		size;

	size = 0;
	while (str[i] && str[i] != ' ' && !ft_is_quote(str[i])
		&& !is_spc(str[i]))
	{
		i++;
		size++;
	}
	new = ft_calloc(1, size + 1);
	if (!new)
		return (NULL);
	return (new);
}

char	*ft_get_env(char *str, int *i)
{
	int		j;
	char	*new;
	char	*env;

	j = 0;
	new = count_size_and_allocate(str, *i);
	while (str[(*i)] && str[(*i)] != ' '
		&& !ft_is_quote(str[(*i)]) && !is_spc(str[(*i)]))
		new[j++] = str[(*i)++];
	new[j] = '\0';
	env = get_env(new);
	return (env);
}

char	*ft_expand(char *str)
{
	int		size;
	char	*new;

	size = count_size(str);
	new = (char *)ft_calloc(sizeof(char), (size + 1));
	if (!new)
		return (NULL);
	new = ft_copy(str, new);
	return (new);
}
