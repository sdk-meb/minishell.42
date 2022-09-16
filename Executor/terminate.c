/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:02:59 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/16 15:30:41 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	ft_exit(int ex_it)
{
	c_delete(TEMPORARY, EMPTY);
	c_delete(APPROVED, EMPTY);
	free(ft__env(NULL));
	if (glb_sig(EMPTY) == RL_STATE_READCMD)
		printf(" exit\n");
	exit(ex_it);
}
