/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:02:59 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/03 17:51:50 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	ft_exit(int ex_it, bool pros)
{
	if (pros == PRIO_PROCESS + 1)
		c_delete(TEMPORARY, EMPTY);
	c_delete(TEMPORARY, EMPTY);
	exit(ex_it);
}
