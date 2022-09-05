/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_loc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:03:38 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/05 14:42:48 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

int	stat_loc(int statu)
{
	static int	qm;

	if (statu != EMPTY)
		qm = statu;
	return (qm);
}

void	track_child(int statu)
{
	if (WIFSIGNALED(statu))
	{
		if (statu == 3)
			ft_err("Quit: 3", 109);
		if (statu == 9)
			ft_err("Killed: 9", 109);
		stat_loc(WTERMSIG(statu) + 128);
	}
	else if (WSTOPSIG(statu) == 127 || WEXITSTATUS(statu) == 127)
		stat_loc(WSTOPSIG(statu));
	else
		stat_loc(WSTOPSIG(statu));
}
