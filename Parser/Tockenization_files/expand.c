/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:49:40 by rel-hach          #+#    #+#             */
/*   Updated: 2022/09/01 20:06:53 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

char	*ft_get_env(char *str, int *i)
{
	int		j;
	char	temp[1000000];
	char	*env;

	j = 0;
	while (str[(*i)] && str[(*i)] != ' ' && !ft_is_quote(str[(*i)])
		&& str[(*i)] != '$')
		temp[j++] = str[(*i)++];
	temp[j] = '\0';
	env = ft_strdup(get_env(temp));
	return (env);
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
