/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:11:49 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/20 16:59:42 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	else
		return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (!dstsize)
		return (ft_strlen(src));
	while (*s && --dstsize)
		*d++ = *s++;
	*d = '\0';
	return (ft_strlen(src));
}

//________________________________________________

int	ft_get_next_quote(int i, char *line)
{
	char	quote_type;

	quote_type = line[i++];
	while (line[i] && line[i] != quote_type)
		i++;
	return (i);
}

char	**ft_freestr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
	return (NULL);
}

// _____________________________________________-

int	ft_count_tokens(char *s)
{
	static int	count;
	static int	i;

	while (s[i])
	{
		while (s[i] == SPACE)
			i++;
		if (ft_is_quote(s[i]))
		{
			i = ft_get_next_quote(i, s);
			while (ft_is_quote(s[i + 1]))
				i = ft_get_next_quote(i + 1, s);
			count++;
			i++;
		}
		else if (s[i] != SPACE && s[i])
			count++;
		while (s[i] != SPACE && s[i])
		{
			if (ft_is_quote(s[i]))
				i = ft_get_next_quote(i, s);
			i++;
		}
	}
	return (count);
}

char	*ft_create_tokens(char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (ft_is_quote(s[i]))
	{
		i = ft_get_next_quote(i, s);
		i++;
	}
	while (s[i] && s[i] != ' ')
	{
		if (ft_is_quote(s[i]))
			i = ft_get_next_quote(i, s);
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str)
	{
		ft_strlcpy(str, s, i + 1);
		return (str);
	}
	return (NULL);
}

char	**ft_tokenize_line(char *s)
{
	int		i;
	int		nb_tokens;
	char	**tdstr;	

	if (s)
	{
		nb_tokens = ft_count_tokens(s);
		printf("number of tokens = %d\n", nb_tokens);
		tdstr = (char **)malloc(sizeof(char *) * (nb_tokens + 1));
		if (tdstr)
		{
			i = -1;
			while (++i < nb_tokens)
			{
				while (*s == SPACE)
					s++;
				tdstr[i] = ft_create_tokens(s);
				if (!tdstr[i])
					return (ft_freestr(tdstr));
				s = s + ft_strlen(tdstr[i]);
			}
			tdstr[i] = 0;
			return (tdstr);
		}
	}
	return (NULL);
}

int	main ()
{
	char	*str = "----------- ------ ' ---- --------- '";
	char	**new = ft_tokenize_line(str);
	int		i = 0;
	while (new[i])
	{
		printf("\n%d = %s", i, new[i]);
		i++;
	}
}