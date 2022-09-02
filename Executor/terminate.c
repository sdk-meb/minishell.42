/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:02:59 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/02 18:42:59 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

t_cmd	save_get_cmd(void **cmd)
{
	static void **cmmd;

	if (cmd && *cmd)
		cmmd = cmd;
	return ((t_cmd)*cmd);
}

void	free_tree(t_cmd cmd)
{
	if (!cmd)
		return ;
	if (cmd->symbol == '|')
	{
		free_tree(cmd->right);
		free_tree(cmd->left);
		freen((void **)&(cmd));
		return ;
	}
	freen((void **)&(cmd->token));
	freen((void **)&(cmd->var));
	freen((void **)&(cmd->file));
	freen((void **)&(cmd->type));
	if (cmd->arv)
		ft_freestr(cmd->arv);
	free_tree(cmd->next);
	free (cmd);
	cmd = NULL;
}	

void	ft_exit(int ex_it, bool pros)
{
	glb_sig(RL_STATE_READCMD);
	free_tree(save_get_cmd(NULL));
	if (pros == PRIO_PROCESS + 1)
		my_env(NULL, EMPTY);
	exit(ex_it);
}
