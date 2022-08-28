/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Subsystem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:19:52 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/28 10:23:16 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SUBSYSTEM_H
# define SUBSYSTEM_H

# include "minishell.h"
/*
	structure indicate the global shell variable
		from envirenment and exported
*/

typedef struct s_envv
{
	t_str			name;
	t_str			content;
	bool			eq;
	int				sort;
	struct s_envv	*next;
}	t_envv;

t_envv	**my_env(t_envv **env, t_req ord);/* get global environment */

void	env_proc(char **env_v, t_str var); /* environment processing */
void	*get_env(t_str var);
void	set_env(t_str var);
void	unset_envv(t_str var);
char	**env_to_argv(t_envv **env);
/* buiting command */
void	env(t_cmd cmd);

void	unset(t_cmd cmd);
void	export(t_cmd cmd);

#endif
