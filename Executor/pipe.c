/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:45:59 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/18 10:59:51 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void ft_pipe(int fds[3][2], t_req ord)
{
	if (ord == _GET)
	{
		pipe(fds[STDIN_FILENO - 1]);
		dup2(fds[STDIN_FILENO - 1][STDIN_FILENO], STDIN_FILENO);
		pipe(fds[STDOUT_FILENO - 1]);
		dup2(fds[STDOUT_FILENO - 1][STDOUT_FILENO], STDOUT_FILENO);
		// pipe(fds[STDERR_FILENO - 1]);
		// dup2(fds[STDERR_FILENO - 1][STDERR_FILENO], STDERR_FILENO);
		return;
	}
	close(fds[STDIN_FILENO][0]);
	close(fds[STDIN_FILENO][1]);
	close(fds[STDOUT_FILENO][0]);
	close(fds[STDOUT_FILENO][1]);
	// close(fds[STDERR_FILENO][0]);
	// close(fds[STDERR_FILENO][1]);
}
