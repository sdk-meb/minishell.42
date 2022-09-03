// HEADER 42 ____ USER = rel-hach //

#include "../../Include/minishell.h"

char *heredoc_waiting(int fds[2])
{
	char	*temp;
	int		status;

	close(fds[STDOUT_FILENO]);
	wait(&status);
	if (status ==  0)
		glb_sig(_EXECUTE_OK);
	temp = ft_calloc(OPEN_MAX + 1 , 1);
	status = read(fds[STDIN_FILENO], temp, OPEN_MAX);
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
	return (new_delim);
}

char	*ft_remove_quotes(char *delim)
{
	int		size;
	char	*new;

	size = ft_strlen(delim) - 2;
	new = ft_calloc(sizeof(char ), size + 1);
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
	glb_sig(HEREDOC);
	if (fork())
		return (heredoc_waiting(fds));
	signal(SIGINT, SIG_DFL);
	rl_clear_history();
	close(fds[STDIN_FILENO]);
	if (!ft_is_quote(delim[0]))
		quote = 0;
//	if (quotes_are_closed(delim))
//		exit (1);
	delim = ft_remove_quotes(delim);
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(delim, line) == 0)
			break ;
		if (quote == 0)
			line = ft_expand_heredoc(line);
		write(fds[STDOUT_FILENO], line, ft_strlen(line));
		write(fds[STDOUT_FILENO], "\n", 1);
	}
	close(fds[STDOUT_FILENO]);
	exit(SUCCESS);//	return (ft_exit(SUCCESS, RUSAGE_CHILDREN + 1), NULL);

}

char **handel_heredoc(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], "<<") == 0)
		{
			str[i + 1] = ft_heredoc(str[i + 1]);
		}
		i++;
	}
	return (str);
}
