/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:39:35 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/02 12:56:59 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/shell.h"
/*
    Single 	Quotes 					" quote>
    Double 	Quotes 					' dquote>
    Back 	Quotes					` bquote>
	Start character-set wildcard  	[[ cond>
	Start command block           	{ cursh>
*/

bool	quotes_are_closed(_str line)
{
	int		i;
	char	type_quote;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '\'' || line[i] == '\"') && line[i - 1] != '\\')
		{
			type_quote = line[i++];
			while (line[i] && line[i] != type_quote)
				i++;
			if (!line[i])
				return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
