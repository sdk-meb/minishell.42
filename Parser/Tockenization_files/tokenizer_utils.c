// HEADER 42 ___ BY = Rel-hach //

#include "../../Include/minishell.h"

void	skip_space(char *str, int *i)
{
	while (str[*i])
		(*i)++;
}

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