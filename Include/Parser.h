/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:53:03 by rel-hach          #+#    #+#             */
/*   Updated: 2022/08/22 12:37:41 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PARSER_H
# define PARSER_H

// Used libraries :

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>

// Definition :

# define SUCCESS	0
# define FAILURE	1


// Used structs :

typedef struct s_common_core
{
	int				fds[2];
	bool			err;
	int				arc;
	char			**arv;
}				t_common_addr;

typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}	t_env;

typedef struct s_list
{
	char			*token;
	char			type;

	struct s_list	*next;
	struct s_list	*prev;
	struct s_list	*left;
	struct s_list	*right;

	t_common_addr	*cm;
}	t_list;

// [A] Tockenization files :

// 1 // repair line 

void	ft_fill_quotes(char *old_line, char *new_line, int *i, int *j);
void	ft_add_space_spchar(char *str, char *new, int *i, int *j);
int		ft_count_special_characters(char *str);
char	*ft_repair_string(char *old_line);

// 2 // branch_line

//char	**ft_branch_line(char *line, char c);
int		ft_check_chars(char c, char *set);
int		ft_get_next_quote(int i, char *line);
int		ft_calculate_words(char *line, char c);
char	*ft_allocate_fill_str(char *line);
char	**ft_free_strings(char **ptr);

// [B] Parsing files :

t_list	*return_first_node(t_list *lst);
t_list	*ft_pipe_case(t_list *head);
t_list	*ft_create_astree(t_list *head);
char	**ft_readline(char ps1);
void	ft_call_shell(char ps1);
bool	quotes_are_closed(char *line);
int		ft_check_line(char *line);

// Expandation files :

void	copy_env(char *env, char *new_str, int *j);
void	skip_quote(char *str, int *i);
void	copy(char *new_str, char *str);
char	*ft_get_env(char *str, int *i);
int		count_dq_case(char *str, int *i);
int		count_sq_case(char *str, int *i);
int		count_size(char *str);
void	ft_copy_sq_case(char *str, char *new, int *i, int *j);
void	ft_copy_dq_case(char *str, char *new, int *i, int *j);
char	*ft_copy(char *str, char *new_str);
char	*ft_expand(char *str);

// [C] Execution files :

// [D] Auxiliaries files :

// FILE 1 //

void	print_tree(t_list *root);

// FILE 2 //

int		ft_is_quote(char c);
int		ft_is_pipe(char c);
int		ft_is_redirection(char c);
int		ft_is_special(char c);

// FILE 3 //

int		ft_isprint(int c);

// FILE 4 //

char	**ft_split(char const *s, char c);

// [E] //

// list environnement variables :

t_env	*ft_lstlast_env(t_env *lst);
int		ft_lstsize_env(t_env *lst);
void	ft_lstadd_back(t_env **lst, t_env *new);
t_env	*ft_new_env(char *str);
t_env	*ft_create_list_for_env(char **splitted);

// list tockens :

t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back_doubly(t_list **lst, t_list *new);
t_list	*ft_new_token(char *string);
t_list	*ft_create_list_for_tockens(char **splitted);

int			ft_get_next_quote(int i, char *line);
int			ft_wordscounter(char *s, char c);
char		*ft_write_words(char *s, char c);
char		**ft_branch_line(char *s, char c);

#endif