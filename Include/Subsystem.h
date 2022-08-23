/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Subsystem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:19:52 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/23 18:57:24 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

#include "minishell.h"
/*
	structure indicate the global shell variable
		from envirenment and exported
*/


typedef struct s_envv
{
	t_str			name;
	t_str			content;
	int				sort;
	struct s_envv	*next;
}	t_envv;

t_envv	**my_env(t_envv **env, t_req ord);/* get global environment */

void	env_proc(char **env_v, t_str var); /* environment processing */
void	*get_env(t_str var);
/* buiting command */
void	env();

void	unset(t_cmd cmd);
void	export(t_cmd cmd);
//char	**env_as_arg()

#endif
