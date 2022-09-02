/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:11:36 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/02 16:15:01 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

/* signal, sigaction, sigemptyset, sigaddset, kill , fork */

int	glb_sig(int sig)
{
	static int	osig;

	if (sig != EMPTY)
		osig = sig;
	return (osig);
}

static void	help_child(t_cmd cmd, void (*bin)(t_cmd))
{
	int	statu;

	statu = -1;
	while (statu++ < 255)
		if (statu != cmd->out && statu != cmd->in && statu != STDERR_FILENO)
			close(statu);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	dup2(cmd->in, STDIN_FILENO);
	dup2(cmd->out, STDOUT_FILENO);
	bin(cmd);
	ft_exit (1, RUSAGE_CHILDREN  + 1);
}

void	fork_exec(t_cmd cmd, void (*bin)(t_cmd))
{
	int	statu;

	if (glb_sig(EMPTY) == RL_STATE_READCMD || cmd->in == -1 || cmd->out == -1)
		return ;
	statu = fork();
	if (statu == PRIO_PROCESS)
		help_child(cmd, bin);
	close_fd(&(cmd->in), &(cmd->out));
	if (statu == RUSAGE_CHILDREN)
		ft_err(NULL, errno);
	while (cmd->last == true && waitpid(0, &statu, WUNTRACED) != -1)
		track_child(statu);
	if (cmd->last == true)
		glb_sig(RL_STATE_READCMD);
}

static void	sa_sig(int sig)
{
	if (sig != SIGINT)
		return ;
	if (glb_sig(EMPTY) == HEREDOC || glb_sig(EMPTY) == _EXECUTE_OK)
	{
		write(1, "\n", 1);
		glb_sig(RL_STATE_READCMD);
	}
	else if (glb_sig(EMPTY) == RL_STATE_READCMD)
	{
		track_child(130);
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signal_handler(void)
{
	glb_sig(_EXECUTE_OK);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sa_sig);
}
