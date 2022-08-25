// 42 HEADER ___ BY = rel-hach //

#include "../Include/minishell.h"

void	copy_env(char *env, char *new_str, int *j)
{
	while (*env)
	{
		new_str[(*j)++] = *env;
		env++;
	}
}

void	ft_copy_sq_case(char *str, char *new, int *i, int *j)
{
	(*i)++;
	while (str[(*i)] && str[(*i)] != '\'')
		new[(*j)++] = str[(*i)++];
	(*i)++;
}

void	ft_copy_dq_case(char *str, char *new, int *i, int *j)
{
	char	*env;

	(*i)++;
	while (str[(*i)] && str[(*i)] != '\"')
	{
		if (str[(*i)] != '$')
			new[(*j)++] = str[(*i)++];
		if (str[(*i)] == '$')
		{
			(*i)++;
			env = ft_get_env(str, i);
			if (env)
				copy_env(env, new, j);
		}
	}
	(*i)++;
}

char	*ft_copy(char *str, char *new_str)
{
	int		i;
	int		j;
	char	*env;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_is_quote(str[i]) && str[i] != '$')
			new_str[j++] = str[i++];
		if (str[i] == '\'')
			ft_copy_sq_case(str, new_str, &i, &j);
		if (str[i] == '\"')
			ft_copy_dq_case(str, new_str, &i, &j);
		if (str[i] == '$')
		{
			i++;
			env = ft_get_env(str, &i);
			if (env)
				copy_env(env, new_str, &j);
		}
	}
	new_str[j] = '\0';
	return (new_str);
}