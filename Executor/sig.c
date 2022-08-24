/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:11:36 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/24 12:14:30 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

/* signal, sigaction, sigemptyset, sigaddset, kill , fork */

void	fork_exec(t_cmd cmd, void (*bin)(t_cmd))
{
	pid_t	id;

	id = fork();
	errno = 0;
	if (id == PRIO_PROCESS)
	{
		signal(SIGINT, SIG_DFL);
		if (cmd->in != STDIN_FILENO)
			dup2(cmd->in, STDIN_FILENO);
		if (cmd->out != STDOUT_FILENO)
			dup2(cmd->out, STDOUT_FILENO);
		bin(cmd);
		ft_err(cmd->token, errno);
		exit(stat_loc(-42));
	}
	close_fd(cmd->in, cmd->out);
	signal(SIGINT, SIG_IGN);
	wait(&id);
	stat_loc(WEXITSTATUS(id));
	signal_handler();
}

static void	sa_sig(int sig)
{
	c_delete(TEMPORARY, EMPTY);
	if (sig == SIGINT)
	{
		printf("\n");
		stat_loc(1);
		ft_call_shell(PRIO_USER);
	}
}

void	signal_handler(void)
{
	struct sigaction	act;
	struct sigaction	oact;

	sigemptyset(&(act.sa_mask));
	act.sa_handler = sa_sig;
	signal(SIGQUIT, SIG_IGN);
	sigaction(SIGINT, &act, &oact);
}
