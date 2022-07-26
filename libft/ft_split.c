/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:18:49 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/05 09:06:03 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(const char *str, char c)
{
	int		i;
	t_ptr	ptr;
	int		r;

	i = 0;
	ptr = (t_ptr)str;
	r = 0;
	if (!ptr)
		return (0);
	while (*ptr)
	{
		if (*ptr != c && r == 0)
		{
			r = 1;
			i++;
		}
		else if (*ptr == c)
			r = 0;
		ptr++;
	}
	return (i);
}

static char	**s_free(char **f)
{
	perror("split :: exit ");
	exit (44);
	while (*f)
		free(*f++);
	free (f);
	return (NULL);
}

static char	*ft_sub(const char *str, int start, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc((len - start + 1), sizeof(char));
	if (!word || !str)
	{
		perror("split :: exit ");
		exit (44);
		free (word);
		return (NULL);
	}
	while (start < len)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	t_intgr	spl;
	char	**h;

	if (!s)
		return (NULL);
	h = ft_calloc((ft_words(s, c) + 1), sizeof(char *));
	if (!h)
		return (NULL);
	spl.i = -1;
	spl.j = 0;
	spl.n = -1;
	while (++(spl.i) <= (int)ft_strlen(s))
	{
		if (s[spl.i] != c && spl.n < 0)
			spl.n = spl.i;
		else if ((s[spl.i] == c || spl.i == (int)ft_strlen(s)) && spl.n >= 0)
		{
			h[spl.j] = ft_sub(s, spl.n, spl.i);
			if (!h[spl.j++])
				return (s_free(h));
			spl.n = -1;
		}
	}
	h[spl.j] = NULL;
	return (h);
}
