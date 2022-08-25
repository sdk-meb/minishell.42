// HEADER 42 ____ USER = rel-hach //

#include "../Include/minishell.h"

int    ft_heredoc(t_list *head)
{
    int     fd[2];
    char    *line;

    pipe(fd);
    while (1)
    {
        line = readline("> ");
        if (!line || ft_strcmp(head->token, line) == 0)
        {
            free(line);
            close(fd[1]);
            return (fd[0]);
        }
        ft_putstr_fd(line, fd[1]);
        ft_putstr_fd("\n", fd[0]);
        free(line);
    }
}