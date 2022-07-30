
#include <minishell.h>

/*
int	ft_is_operator_par(char	*str)
{
	if (!ft_strcmp(str, "&&") || !ft_strcmp(str, "||") || !ft_strcmp(str, "|"))
		return (1);
	return (0);
}

int	ft_is_pipe(char *str)
{
	if (!ft_strcmp(str, "|"))
		return (1);
	return (0);
}

int	ft_is_parenth(char *str)
{
	if (!ft_strcmp(str, "(") || !ft_strcmp(str, ")"))
		return (1);
	return (0);
}


t_list	*ft_handel_right(t_list *head)
{
	t_list	*temp;

	temp = head->next;
	while (temp != NULL)
	{
		if (ft_)
		temp = temp->next;
	}
}
void	ft_first_step(t_list *head);
{
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (!ft_is_parenth(temp->prev->tocken))
			temp = temp->prev;
		if (!ft_is_parenth(temp->next->tocken))
			temp = temp->next;
		if (ft_is_parenth(temp->prev->tocken))
			temp = temp->prev;
		if (ft_is_parenth(temp->next->tocken))
			temp = temp->next;
		temp = temp->next;
	}
}
*/

t_list	*ft_create_ast_for_par(t_list *head)
{
	t_list	*temp;
	t_list	*root;

	temp = head;
	while (temp != NULL)
	{
		if (!ft_strcmp(temp->tocken, "("))
			root = ft_create_astree(temp);
		temp = temp->next;
	}
	return (root);
}
