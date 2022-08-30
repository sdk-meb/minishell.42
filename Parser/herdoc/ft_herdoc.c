// HEADER 42 ____ USER = rel-hach //

#include "../Include/minishell.h"

char    *ft_heredoc(char *delim)
{
    char    *line;
    char    *temp;

    temp = malloc(sizeof(char *));
    while (1)
    {
        line = readline("> ");
        if (!line || ft_strcmp(delim, line) == 0)
        {
            free(line);
            return (temp);
        }
        temp = ft_strjoin(temp, "\n");
        temp = ft_strjoin(temp, line);
        free(line);
    }
    return (temp);
}

char    **handel_heredoc(char **str)
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