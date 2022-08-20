/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:11:36 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/20 11:54:53 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

/* signal, sigaction, sigemptyset, sigaddset, kill */

void	sa_sig(int sig, siginfo_t *info, void *parm)
{
	(void)parm;
	(void)info;
	c_delete(TEMPORARY, EMPTY);
	// system("leaks minishell");
	if (sig == SIGINT)
	{
		printf("\n");
		errno = 130;
		ft_call_shell(PRIO_USER);
	}
	else if (sig == SIGQUIT)
	{
		errno = 131;
		ft_call_shell(EMPTY);
	}
}

void	signal_handler(void)
{
	struct sigaction	act;
	struct sigaction	oact;

	sigemptyset(&(act.sa_mask));
	sigaddset(&(act.sa_mask), SA_SIGINFO);
	act.sa_sigaction = sa_sig;
	sigaction(SIGINT, &act, &oact);
	sigaction(SIGQUIT, &act, &oact);
	sigaction(SIGCHLD, &act, &oact);
}
