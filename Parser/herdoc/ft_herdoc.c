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
	temp = ft_calloc(100001 , 1);
	status = read(fds[STDIN_FILENO], temp, 10000);
	if (status < 0)
		return NULL;
	temp[status] = '\0';
	close(fds[STDIN_FILENO]);
	return (temp);
}

char	*ft_heredoc(char *delim)
{
	char	*line;
	int		fds[2];

	pipe(fds);
	glb_sig(SIGCHLD);
	if (fork())
		return (heredoc_waiting(fds));
	signal(SIGINT, SIG_DFL);
	close(fds[STDIN_FILENO]);
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(delim, line) == 0)
		{
			free(line);
			break;
		}
		if (ft_is_quote(delim[0]) == 0)
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

	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], "<<") == 0)
			str[i + 1] = ft_heredoc(str[i + 1]);
		i++;
	}
	return (str);
}
