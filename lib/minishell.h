/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 02:10:56 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/03 20:05:29 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include <sys/stat.h>
# include <termios.h>

# include "types__.h"

typedef struct s_fd
{
	int	in;
	int	out;
}	t_fd;

typedef struct s_env
{
	_str			name;
	_str			value;
	struct s_env	*next;
}	t_env_v;

typedef struct s_list
{
	_str			tocken;
	_str			type;
	int				position;
	t_fd			*fd;
	struct s_list	*left;
	struct s_list	*right;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

//used functions :

int			ft_wordscounter(_str s, char c);
_str		ft_write_words(_str s, char c);
_2d_arr		ft_split_line(_str s, char c);
void		ft_skip_space(_str line, int *i);
int			ft_get_next_quote(int i, _str line);
void		ft_tocken(_str line);
_str		ft_get_type(_str tocken);
t_list		*ft_create_a_new_node(_str line);
t_list		*ft_lstlast(t_list *lst);
t_env_v		*new_env(_str str);/* ft_create_list_for_env */
t_list		*ft_create_list_for_tockens(_2d_arr plitted);

// LIST :

void		ft_lstadd_back_doubly(t_list **lst, t_list *new);

//

bool			ft_is_special(char c);
bool			ft_is_quote(char c);
bool			ft_is_pipe(char c);
bool			ft_is_and(char c);
bool			ft_is_operator(_str str);
bool			ft_is_parenthesis(char c);
bool			ft_is_redirection(char c);

// AST

t_list		*get_right_pipe_or_cmd(t_list *lst_pipe);
t_list		*get_the_left_operator_or_cmd(t_list *lst_operator);
t_list		*ft_create_astree(t_list *head);

// AST

void		ft_minishell(t_env env);/*(1)*/
_2d_arr		ft_readline(char);/*(2)*/
t_list		*ft_get_right_operator(t_list *head);
t_list		*ft_get_left_operator(t_list *head);
t_list		*ft_right(t_list	*head);
t_list		*ft_left(t_list	*head);
t_list		*ft_create_tree_get_root(t_list *head);
t_list		*ft_create_astree_for_parenthesis(t_list *head);
t_list		*ft_create_ast_for_par(t_list *head);
void		paren_case(t_list *head);
void		ft_lstadd_back(t_env_v **lst, t_env_v *new);
t_list		*ft_pipe_case(t_list *head);
t_list		*return_first_node(t_list *lst);
bool			ft_is_operator(_str str);


bool	quotes_are_closed(_str line);

#endif