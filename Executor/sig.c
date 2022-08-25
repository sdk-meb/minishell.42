/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:11:36 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/25 19:52:47 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

/* signal, sigaction, sigemptyset, sigaddset, kill , fork */

int	glb_sig(int sig)
{
	static int	osig;

	if (sig == SIGINT || sig == SIGCHLD)
		osig = sig;
	return (osig);
}

static void	sa_sig(int sig)
{
	if (sig == SIGINT && glb == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	fork_exec(t_cmd cmd, void (*bin)(t_cmd))
{
	pid_t	id;

	id = fork();
	if (id == PRIO_PROCESS)
	{
		signal_handler(TEMPORARY);
		if (cmd->in != STDIN_FILENO)
			dup2(cmd->in, STDIN_FILENO);
		if (cmd->out != STDOUT_FILENO)
			dup2(cmd->out, STDOUT_FILENO);
		return (bin(cmd));
	}
	glb_sig(SIGCHLD);
	close_fd(cmd->in, cmd->out);
	if (id == RUSAGE_CHILDREN)
		ft_err(NULL, errno);
	wait(&id);
	glb_sig(SIGINT);
	return ;
}

void	signal_handler(t_req ord)
{
	if (ord == TEMPORARY)
	{
		signal(SIGQUIT, SIG_DFL);
	}
	else if (ord == APPROVED)
	{
		glb_sig(SIGINT);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, sa_sig);
	}
}
