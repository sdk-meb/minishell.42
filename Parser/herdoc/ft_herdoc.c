// HEADER 42 ____ USER = rel-hach //

#include "../Include/minishell.h"

char *heredoc_waiting(int fds[2])
{
	char	*temp;
	int		statu;

	close(fds[STDOUT_FILENO]);
	wait(&statu);
	glb_sig(SIGINT);
	stat_loc(statu);
	temp = ft_calloc(100001 , 1);
	statu = read(fds[STDIN_FILENO], temp, 10000);
	if (statu < 0)
		return NULL;
	temp[statu] = '\0';
	close(fds[STDIN_FILENO]);
	return (temp);
}

char *ft_heredoc(char *delim)
{
	char *line;
	int fds[2];

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
		write(fds[STDOUT_FILENO], line, ft_strlen(line));
		write(fds[STDOUT_FILENO], "\n", 1);
		free(line);
	}
	close(fds[STDOUT_FILENO]);
	exit(SUCCESS);
}

char **handel_heredoc(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], "<<") == 0)
			str[i + 1] = ft_heredoc(str[i + 1]);
		i++;
	}
	return (str);
}