# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <string.h>
#include "Include/minishell.h"

int	ft_is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	else
		return (0);
}

char	*get_env(char *str, int *len)
{
	char	*env;
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] && str[j] != ' ' && str[j] != '$' && !ft_is_quote(str[j]))
		j++;
	env = malloc(sizeof(char) * (j + 1));
	if (!env)
		return (NULL);
	while (i < j)
	{
		env[i] = str[i];
		i++;
	}
	env[i] = '\0';
	new = getenv(env);
	(*len) = (*len) + j + 1;
	return (free(env), new);
}

void	get_size_between_double_bracket(char *str, int *i, int *size, int *minus)
{
	(*i)++;
	while (str[*i] != '\"')
	{
		if (str[(*i)] == '$')
			*size = strlen(get_env(&str[++(*i)], minus)) + *size;
		(*i)++;
		(*size)++;
	}
	printf("\nDOUBLE = %d\n", (*size));
	*size -= 1;
}

void	get_size_between_single_bracket(char *str, int *i, int *size)
{
	(*i)++;
	while (str[(*i)] != '\'')
	{
		(*size)++;
		(*i)++;
	}
	*size -= 1;
}

void	test_t(char *str)
{
	int	i;
	int	minus;
	int	size;

	i = 0;
	size = 0;
	minus = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			get_size_between_double_bracket(str, &i, &size, &minus);
		if (str[i] == '\'')
			get_size_between_single_bracket(str, &i, &size);
		if (str[i] == '$')
			size = strlen(get_env(&str[++i], &minus)) + size;
		i++;
	}
	printf("%lu\n", size + strlen(str));
}

int	main(void)
{
	char	*str = "'hello $USER'\"hello $USER\"'$USER'";
	test_t(str);
}


char	*the_expander(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (str[i] == '\'')
			ft_calcul and_expand();
		i++;
	}
}

'_____'"_______"