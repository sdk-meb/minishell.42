/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:00:29 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/13 12:58:13 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Include/minishell.h"

// int	ft_wordscounter(char const *s, char c)
// {
// 	int	count;
// 	int	i;

// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		while (s[i] == c)
// 			i++;
// 		if (s[i] != c && s[i])
// 			count++;
// 		while (s[i] != c && s[i])
// 			i++;
// 	}
// 	return (count);
// }

// char	*ft_write_words(char const *s, char c)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	while (s[i] && s[i] != c)
// 		i++;
// 	str = (char *)malloc(sizeof(char) * (i + 1));
// 	if (str)
// 	{
// 		ft_strlcpy(str, s, i + 1);
// 		return (str);
// 	}
// 	return (NULL);
// }

// char	**ft_free_string(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		free (tab[i]);
// 		i++;
// 	}
// 	free (tab);
// 	return (NULL);
// }

// char	**ft_split(char const *s, char c)
// {
// 	int		i;
// 	int		nb_words;
// 	char	**tdstr;

// 	if (s)
// 	{
// 		nb_words = ft_wordscounter(s, c);
// 		tdstr = (char **)malloc(sizeof(char *) * (nb_words + 1));
// 		if (!tdstr)
// 			return (NULL);
// 		i = -1;
// 		while (++i < nb_words)
// 		{
// 			while (*s == c)
// 				s++;
// 			tdstr[i] = ft_write_words(s, c);
// 			if (!tdstr[i])
// 				return (ft_free_string(tdstr));
// 			s = s + ft_strlen(tdstr[i]);
// 		}
// 		tdstr[i] = 0;
// 		return (tdstr);
// 	}
// 	return (NULL);
// }
