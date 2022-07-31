/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 02:10:56 by rel-hach          #+#    #+#             */
/*   Updated: 2022/07/29 16:45:42 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>


typedef struct s_fd
{
	int	in;
	int	out;
}	t_fd;

typedef struct s_list
{
	char			*tocken;			/* type = word "sss$USER" type = dquotes | type Env */
	char			*type;
	int				position;
	t_fd			*fd;
	struct s_list	*left;
	struct s_list	*right;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

//used functions :

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_wordscounter(char *s, char c);
char		*ft_write_words(char *s, char c);
//static char	**ft_freestr(char **tab);
char		**ft_split(char *s, char c);
void		ft_skip_space(char *line, int *i);
int			ft_get_next_quote(int i, char *line);
void		ft_tocken(char *line);
int			ft_strcmp(char *s1, char *s2);
char		*ft_get_type(char *tocken);
t_list		*ft_create_a_new_node(char *line);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
void		*ft_calloc(size_t count, size_t size);


// 

int			ft_is_special(char c);
int			ft_is_quote(char c);
int			ft_is_pipe(char c);
int			ft_is_and(char c);
int			ft_is_operator(char *str);
int			ft_is_parenthesis(char c);
int			ft_is_redirection(char c);

// AST

t_list		*get_right_pipe_or_cmd(t_list *lst_pipe);
t_list		*get_the_left_operator_or_cmd(t_list *lst_operator);
t_list		*ft_create_astree(t_list *head);

// AST 

t_list	*ft_get_right_operator(t_list *head);
t_list	*ft_get_left_operator(t_list *head);
t_list	*ft_right(t_list	*head);
t_list	*ft_left(t_list	*head);
t_list	*ft_create_tree_get_root(t_list *head);
t_list	*ft_create_astree_for_parenthesis(t_list *head);
t_list	*ft_create_ast_for_par(t_list *head);
void	paren_case(t_list *head);

int	parser_main(int ac, char **av, char **env);




#endif