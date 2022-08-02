
#include "../lib/shell.h"

int	ft_check_line(_str	line)
{
	if (quotes_are_closed(line))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

_str	prompt(char c)
{
	if (c == ROOT)
		return ((_str)ft_strdup("msh~1.0#>"));
	if (c == USER)
		return ((_str)ft_strdup("msh~1.0$>"));
	if (c == '\'')
		return ((_str)ft_strdup("quote>"));
	if (c == '\"')
		return ((_str)ft_strdup("dquote>"));
	if (c == '\\')
		return ((_str)ft_strdup(">"));
	if (c == '|')
		return ((_str)ft_strdup("pipe>"));
	return (NULL);
}

_2d_arr	ft_readline()
{
	_str	line;
	_2d_arr	splitted;

	line = readline(prompt(get("USER")));
	if (ft_isprint(line[0]))
		add_history(line);
	if (ft_check_line(line))
		ft_readline();
//	line = ft_repair(line);
	splitted = (_2d_arr)ft_split(line, ' ');
	free((void *)line);
	return (splitted);
}