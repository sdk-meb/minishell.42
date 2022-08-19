/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exuc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:41 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/19 12:18:14 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

//static
void	exec_bin(t_path p_file, t_head arg)
{
	t_req	permit;
	t_head	pathname;
	pid_t	i;

	i = fork();
	if (i)
	{
		int status;
		waitpid(i, &status, WNOHANG);
		printf("WIFEXITED(status) = %d\n", WIFEXITED(status));
		return;
	}
	pathname = (t_head)ft_split(getenv("PATH"), ':');
	while (pathname[i])
	{
		ft_strjoin(pathname[i], "/");
		permit = access(ft_strjoin(pathname[i++], p_file), F_OK);
		if (permit)
			execve(p_file, (char *const *)arg, my_env(NULL, _GET));/* Overlay (programming) */
	}
	ft_err(p_file, ERRMSG);
	exit(errno);
}


static void mng_exec(t_cmd	cmd)
{
	t_cmd	mngr;
//	t_head	av;
	int		lenth;

	mngr = cmd->next;
	lenth = 0;
	while (mngr)/* counting length to reserve argument values for this command */
	{
		if (mngr->type == 'w')
			lenth += 1;
		else if (mngr->type == '>')
			lenth -= 1;/*one file after*/
		else if (mngr->type == '<')
		{
			lenth -= 1;/*all name after must be file*/
		}
		mngr = mngr->next;	
	}
}

void sh_exec(t_cmd cmd)
{
	if (!cmd)
		return;
	if (cmd->type == '|')
	{
		pipe_x (cmd, _GET);
		mng_exec(cmd->left);
//		if (bult_c(cmd))
//			mng_bin(cmd);
		return (sh_exec(cmd->right));
	}
//	if (bult_c(cmd))
//		mng_bin(cmd);
}
