/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Subsystem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:19:52 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/21 13:09:05 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

#include "minishell.h"
/*
	structure indicate the global shell variable
		from envirenment and exported
*/

char	**my_env(char **env, t_req);		 /* get global environment */
void	*_get_env(t_str var);				 /* get one (variabl) of environment */
void	env_proc(char **env, t_str, t_req); /* environment processing */
/* buiting command */
void	env();
void	set_env(t_str var);

void    unset(t_cmd cmd);
void    export(t_cmd cmd);

#endif
