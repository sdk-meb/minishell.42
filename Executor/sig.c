/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:11:36 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/26 21:17:04 by mes-sadk         ###   ########.fr       */
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
	if (sig == SIGINT && glb == _EXECUTE_OK)
		glb_sig(RL_STATE_READCMD);
	if (sig == SIGINT && glb == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	if (sig == SIGQUIT && glb == SIGCHLD)
		ft_err("Quit: 3\n", 109);
}

void	fork_exec(t_cmd cmd, void (*bin)(t_cmd))
{
	pid_t	id;

	id = fork();
	if (id == PRIO_PROCESS)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		dup2(cmd->in, STDIN_FILENO);
		dup2(cmd->out, STDOUT_FILENO);
		return (bin(cmd));
	}
	glb_sig(SIGCHLD);
	close_fd(cmd->in, cmd->out);
	if (id == RUSAGE_CHILDREN)
		ft_err(NULL, errno);
	wait(&id);
	glb_sig(SIGINT);
}

void	signal_handler()
{
	glb_sig(SIGINT);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sa_sig);
}
