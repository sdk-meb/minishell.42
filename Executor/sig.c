/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:11:36 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/23 02:47:02 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

/* signal, sigaction, sigemptyset, sigaddset, kill , fork */

void	fork_exec(t_cmd cmd, void (*bin)(t_cmd))
{
	pid_t	id;

	id = fork();
	if (id == PRIO_PROCESS)
	{
		errno = 0;
		signal(SIGINT, SIG_DFL);
		if (cmd->in != STDIN_FILENO)
			dup2(cmd->in, STDIN_FILENO);
		if (cmd->out != STDOUT_FILENO)
			dup2(cmd->out, STDOUT_FILENO);
		bin(cmd);
		ft_err(NULL, errno);
		exit(errno);
	}
	if (cmd->in != STDIN_FILENO)
		close(cmd->in);
	if (cmd->out != STDOUT_FILENO)
		close(cmd->out);
	if (id == RUSAGE_CHILDREN)
		ft_err(NULL, errno);
	waitpid(id, 0, 0);
}

static void	sa_sig(int sig, siginfo_t *info, void *parm)
{
	(void)parm;
	(void)info;
	c_delete(TEMPORARY, EMPTY);
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
	signal(SIGQUIT, SIG_IGN);
	sigaction(SIGINT, &act, &oact);
//	sigaction(SIGCHLD, &act, &oact);
}
