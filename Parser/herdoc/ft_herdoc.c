/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_herdoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:14:09 by rel-hach          #+#    #+#             */
/*   Updated: 2022/09/11 08:34:04 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

char	*heredoc_waiting(int fds[2])
{
	char	*temp;
	int		status;

	close(fds[STDOUT_FILENO]);
	wait(&status);
	stat_loc(status);
	glb_sig(RL_STATE_READCMD);
	if (status != 0)
		return (NULL);
	glb_sig(_EXECUTE_OK);
	temp = ft_calloc(OPEN_MAX + 1, 1);
	status = read(fds[STDIN_FILENO], temp, OPEN_MAX);
	if (status < 0)
		return (NULL);
	temp[status] = '\0';
	close(fds[STDIN_FILENO]);
	return (temp);
}

char	*ft_rm_quotes(char *delim, int *quote)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	*quote = 1;
	while (delim[i])
	{
		if (ft_is_quote(delim[i]))
		{
			c = delim[i++];
			while (delim[i] && delim[i++] != c)
				j++;
			i++;
		}
		else if (!ft_is_quote(delim[i]))
		{
			i++;
			j++;
		}
	}
	return (copy_new_delim(delim, ft_allocate(j)));
}

void	ft_read(char *line, int *fds, int *quote, char *delim)
{
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(delim, line) == 0)
			break ;
		if (*quote == 0)
			line = ft_expand_heredoc(line);
		write(fds[STDOUT_FILENO], line, ft_strlen(line));
		write(fds[STDOUT_FILENO], "\n", 1);
		free(line);
	}
}

char	*ft_heredoc(char *delim)
{
	char	*line;
	int		fds[2];
	int		quote;

	quote = 0;
	if (pipe(fds) == -1)
		return (NULL);
	glb_sig(HEREDOC);
	if (fork())
		return (heredoc_waiting(fds));
	signal(SIGINT, SIG_DFL);
	rl_clear_history();
	close(fds[STDIN_FILENO]);
	if (quotes_are_closed(delim))
		exit (1);
	if (quotes_is_there(delim))
		delim = ft_rm_quotes(delim, &quote);
	line = NULL;
	ft_read(line, fds, &quote, delim);
	free(line);
	close(fds[STDOUT_FILENO]);
	return (exit(SUCCESS), NULL);
}

char	**handel_heredoc(char **str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (ft_strcmp(str[i], "<<") == 0)
		{
			str[i + 1] = ft_heredoc(str[i + 1]);
		}
		i++;
	}
	return (str);
}
