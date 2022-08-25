// HEADER 42 _________________ BY = rel-hach //

#include "../Include/minishell.h"

int	count_dq_case(char *str, int *i)
{
	int	size;

	size = 0;
	(*i)++;
	while (str[(*i)] && str[(*i)] != '\"')
	{
		if (str[(*i)] == '$')
		{
			(*i)++;
			size = size + ft_strlen(ft_get_env(str, i));
		}
		else
		{
			(*i)++;
			size++;
		}
	}
	(*i)++;
	return (size);
}

int	count_sq_case(char *str, int *i)
{
	int	size;

	size = 0;
	(*i)++;
	while (str[(*i)] && str[(*i)] != '\'')
	{
		(*i)++;
		size++;
	}
	(*i)++;
	return (size);
}

int	count_size(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			size = count_sq_case(str, &i) + size;
		if (str[i] == '\"')
			size = count_dq_case(str, &i) + size;
		if ((str[i]) == '$')
		{
			i++;
			size += ft_strlen(ft_get_env(str, &i));
		}
		if (str[i] != '$' && !ft_is_quote(str[i]))
		{
			i++;
			size++;
		}
	}
	return (size);
}