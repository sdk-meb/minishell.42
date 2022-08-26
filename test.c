#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>


typedef struct s_list
{
	char			*token;
	char			*file;
	char			*type;
	int				fd[2][2];
	struct s_list	*next;
	struct s_list	*prev;
	struct s_list	*left;
	struct s_list	*right;
}	t_list;
void	ft_lstadd_back_doubly(t_list **lst, t_list *new)
{
	t_list		*temp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp = *lst;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
			new->prev = temp;
		}
	}
}


char  *ft_heredoc(char *delim)
{
    char    *line;
    char    *temp;

    temp = malloc(sizeof(char *));
    while (1)
    {
        line = readline("> ");
        if (!line || ft_strncmp(delim, line, 4) == 0)
        {
            free(line);
            return (temp);
        }
        temp = ft_strjoin(temp, " ");
        temp = ft_strjoin(temp, line);
        free(line);
    }
    return (temp);
}

char    **handel_heredoc(char **str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (ft_strncmp(str[i], "<<", 2) == 0)
        {
            temp = str[i + 1];
            str[i + 1] = ft_heredoc(str[i + 1]);
        }
        i++;
    }
    return str;
}

t_list	*ft_new_token(char *string)
{
	int				i;
	t_list			*new;

	new = ft_calloc(1, sizeof(t_list));
	if (!new)
		return (NULL);
	new->token = string;
	//new->type = ft_get_type(string);
	new->prev = NULL;
	new->next = NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

t_list	*ft_create_list_for_tockens(char **splitted)
{
	t_list	*head;
	t_list	*new;
	int		i;

	i = 0;
	head = ft_new_token(splitted[i++]);
	while (splitted[i])
	{
		if (ft_strncmp(splitted[i], "<<", 2) == 0)
        {
			i++;
            while (splitted[i + 1] && ft_strncmp(splitted[i + 1], "<<", 2) == 0)
                i = i + 2;
        }
		new = ft_new_token(splitted[i]);
		ft_lstadd_back_doubly(&head, new);
		i++;
	}
	return (head);
}

int main ()
{
    char    *str = "cat << bbbb << dddd << eeee";
    char **new_str = ft_split(str, ' ');
    new_str = handel_heredoc(new_str);
    int i = 0;
    t_list  *head = ft_create_list_for_tockens(new_str);
    free(new_str);
    //int i = 0;
    while (head)
    {
        printf("%s", head->token);
        head = head->next;
        i++;
    }
}