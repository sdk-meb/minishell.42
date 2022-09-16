/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:11:36 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/16 16:29:49 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

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

	statu = 256;
	while (statu--)
		if (statu != cmd->out && statu != cmd->in && statu != STDERR_FILENO)
			close(statu);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	dup2(cmd->in, STDIN_FILENO);
	dup2(cmd->out, STDOUT_FILENO);
	errno = 0;
	bin(cmd);
	ft_exit (1);
}

void	fork_exec(t_cmd cmd, void (*bin)(t_cmd))
{
	int	statu;

	if (glb_sig(EMPTY) == RL_STATE_READCMD || glb_sig(EMPTY) == EOWNERDEAD
		|| cmd->in == -1 || cmd->out == -1)
		return ;
	statu = fork();
	glb_sig(SIGCHLD);
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
	if (glb_sig(EMPTY) == HEREDOC || glb_sig(EMPTY) == _EXECUTE_OK
		|| glb_sig(EMPTY) == EOWNERDEAD)
	{
		glb_sig(RL_STATE_READCMD);
		write(1, "\n", 1);
	}
	else if (glb_sig(EMPTY) == RL_STATE_READCMD)
	{
		stat_loc(1);
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
