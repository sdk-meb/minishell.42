/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tockenizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:21:56 by rel-hach          #+#    #+#             */
/*   Updated: 2022/07/30 15:15:02 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_tree(t_list *root)
{
	if (root == NULL)
		return ;
	printf("                     I AM ROOT == %s\n", root->tocken);
	if (root->left)
		printf("MY LEFT IS [%s]", root->left->tocken);
	if (root->right)
		printf("				  MY RIGHT IS [%s]\n", root->right->tocken);
	print_tree(root->left);
	print_tree(root->right);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (strlen(src));
}

void	ft_add_space_spchar(char *str, char *new, int *i, int *j)
{
	new[(*j)++] = ' ';
	new[(*j)++] = str[(*i)++];
	if (ft_is_special(str[(*i)]))
		new[(*j)++] = str[(*i)++];
	new[(*j)++] = ' ';
}

int	ft_is_special(char c)
{
	if (!ft_is_pipe(c) && !ft_is_parenthesis(c)
		&& !ft_is_redirection(c) && !ft_is_and(c))
		return (0);
	return (1);
}

int	ft_count_special_characters(char *str)/* ;elv elrn */
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_is_special(str[i]))
		{
			count++;
			if (ft_is_special(str[i + 1]))
				i++;
		}
		i++;
	}
	return (count);
}

char	*ft_repair_string(char *old_line)
{
	int		count;
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	count = ft_count_special_characters(old_line);
	new_line = malloc(sizeof(char) * strlen(old_line) + (count * 2) + 1);
	if (!new_line)
		return (NULL);
	while (old_line[i])
	{
		if (ft_is_special(old_line[i]))
			ft_add_space_spchar(old_line, new_line, &i, &j);
		else
			new_line[j++] = old_line[i++];
	}
	new_line[j] = '\0';
	return (free (old_line), new_line);
}

int	parser_main(int ac, char **av, char **env)
{
	char	*new_line;
	char	*line;
	char	**splitted;
	int		i;
	t_list	*new;
	t_list	*head;
	t_list	*root;

	while (1)
	{
		line = readline("minishell=> ");
		add_history(line);
		new_line = ft_repair_string(line);
		splitted = ft_split(new_line, ' ');
		free(new_line);
		i = 0;
		head = ft_create_a_new_node(splitted[0]);
		i = 1;
		while (splitted[i])
		{
			new = ft_create_a_new_node(splitted[i]);
			ft_lstadd_back(&head, new);
			i++;
		}
		root = ft_create_astree(head);
		//head = ft_lstlast(head);
		// while (head)
		//{
		// 	if (!ft_strcmp(head->tocken, "&&"))
		// 		break;
		// 	head = head->prev;
		//}
		//printf("\n%s\n", head->tocken);
		//root = *ft_create_astree_for_parenthesis(head);
		print_tree(root);
	}
	return 0;
}
