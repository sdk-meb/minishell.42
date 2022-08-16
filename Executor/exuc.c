/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exuc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:41 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/16 18:33:15 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Include/minishell.h"



void    ex_bin(t_path p_file, _head arg)
{
	t_req permit;
	_head	pathname;
	pid_t	i;
	
	i = fork();
	if (i)
	{
		int status;
		waitpid(i, &status, WNOHANG);
		printf("WIFEXITED(status) = %d\n",WIFEXITED(status));
		return ;
	}
	pathname = (_head)ft_split(getenv("PATH"), ':');
	while (pathname[i])
	{
		ft_strjoin(pathname[i], "/");
		permit = access(ft_strjoin(pathname[i++], p_file), F_OK);
		if (permit)
			execve(p_file,( char * const *)arg, NULL);/*Overlay (programming)*/
	}
	ft_err(p_file, ERRMSG);
	exit (errno);
}

void sh_exece(t_cmd cmd)
{
    if (!cmd)
		return ;
	printf("                     I AM cmd == %s\n", cmd->token);
	if (cmd->left)
		printf("MY LEFT IS [%s]", cmd->left->token);
	if (cmd->right)
		printf("				  MY RIGHT IS [%s]\n", cmd->right->token);
	sh_exece(cmd->left);
	sh_exece(cmd->right);
}
