/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:49:40 by rel-hach          #+#    #+#             */
/*   Updated: 2022/09/09 22:22:00 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

char	*ft_get_env(char *str, int *i)
{
	int		j;
	char	temp[ARG_MAX];
	char	*env;

	j = 0;
	while (str[(*i)] && str[(*i)] != ' ' && !ft_is_quote(str[(*i)])
		&& !is_spc(str[(*i)]))
		temp[j++] = str[(*i)++];
	temp[j] = '\0';
	env = get_env(temp);
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
