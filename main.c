/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:31:10 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/18 10:19:26 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Include/minishell.h"

void	ft_minishell()
{
	// if (!fork())
	// {
	// 	signal(SIGCHLD, SIG_DFL);
	// 	kill(0, SIGCHLD);
	// 	signal(SIGINT, SIG_DFL);
	// 	printf("child...\n");		exit(1);
	// }
	ft_call_shell(PRIO_USER);
}

static void	sig()
{
	signal_handler();
}

int	main(int ac, char *av[], char *env[])
{
	sig();
	if (ac == 1)
	{
		env_proc(env, NULL, SAVE);
		ft_minishell();
	}
	else
	{
		opendir(av[1]);
		if (!errno)
			errno = EISDIR;
	 	ft_err(ft_strdup(av[1]), ERRMSG);
		exit (errno);
	}
	return (_RETURN);
}
