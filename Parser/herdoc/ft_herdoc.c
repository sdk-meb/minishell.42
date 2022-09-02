// HEADER 42 ____ USER = rel-hach //

#include "../../Include/minishell.h"

char *heredoc_waiting(int fds[2])
{
	char	*temp;
	int		status;

	close(fds[STDOUT_FILENO]);
	wait(&status);
	glb_sig(SIGINT);
	stat_loc(status);
	temp = ft_calloc(INT32_MAX , 1);
	status = read(fds[STDIN_FILENO], temp, 10000);
	if (status < 0)
		return NULL;
	temp[status] = '\0';
	close(fds[STDIN_FILENO]);
	return (temp);
}

char	*copy_new_delim(char *delim, char *new_delim)
{
	char    c;
    int i;
    int j;

    i = 0;
    j = 0;
    c = delim[i];
    i++;
	while (delim[i] && delim[i] != c)
	{
		new_delim[j++] = delim[i++];
	}
	return (free(delim), new_delim);
}

char	*ft_remove_quotes(char *delim, int quote)
{
	int		i;
	int		j;
	int		size;
	char	*new;

	size = ft_strlen(delim) - 2;
	new = malloc(sizeof(char ) * size + 1);
	if(!new)
		return (NULL);
	return (copy_new_delim(delim, new));
}

char	*ft_heredoc(char *delim)
{
	char	*line;
	int		fds[2];
	int		quote;

	quote = 1;
	pipe(fds);
	glb_sig(SIGCHLD);
	if (fork())
		return (heredoc_waiting(fds));
	signal(SIGINT, SIG_DFL);
	close(fds[STDIN_FILENO]);
	if (ft_is_quote(delim[0]))
		ft_remove_quotes(delim, &quote);
	if (quotes_are_closed(delim))
		exit (1);
    if 
	delim = ft_remove_quotes(delim);
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(delim, line) == 0)
		{
			free(line);
			break;
		}
		if (quote == 0)
			line = ft_expand_heredoc(line);
		write(fds[STDOUT_FILENO], line, ft_strlen(line));
		write(fds[STDOUT_FILENO], "\n", 1);
		free(line);
	}
	close(fds[STDOUT_FILENO]);
	exit(SUCCESS);
}

char **handel_heredoc(char **str)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], "<<") == 0)
		{
			ptr = str[i + 1];
			str[i + 1] = ft_heredoc(str[i + 1]);
			free (ptr);
		}
		i++;
	}
	return (str);
}
