
#include "../lib/shell.h"

int	ft_check_line(_str	line)
{
	if (quotes_are_closed(line))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

_str	prompt(char ps1)
{
	errno = 0;
	if (ps1 == '\'')
		return ((_str)ft_strdup("quote>"));
	if (ps1 == '\"')
		return ((_str)ft_strdup("dquote>"));
	if (ps1 == '\\')
		return ((_str)ft_strdup(">"));
	if (ps1 == '|')
		return ((_str)ft_strdup("pipe>"));
	if (!ft_memcmp(getenv("USER"), "ROOT", 5))
		return ((_str)ft_strdup("msh~1.0#>"));
	if (!ps1)
		return ((_str)ft_strdup("msh~1.0$>"));
	return (NULL);
}

_2d_arr	ft_readline(char ps1)
{
	_str	line;
	t_index	i;
	_2d_arr	splitted;

	i = 0;
	line = readline(prompt(ps1));
	while (line && line[i] && ft_isprint(line[i]))
		i++;
	if (!line || !line[i])
		return (NULL);
	add_history(line);
	if (ft_check_line(line))
		ft_readline(0);
//	line = ft_repair(line);
	splitted = (_2d_arr)ft_split(line, ' ');
	free((void *)line);
	return (splitted);
}