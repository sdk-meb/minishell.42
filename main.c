/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:31:10 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/01 11:11:29 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/minishell.h"

static void	ft_minishell(void)
{
	errno = 0;
	ft_call_shell(PRIO_USER);
}

int	main(int ac, char *av[], char *env[])
{
	signal_handler();
	if (ac == 1)
	{
		env_proc(env, NULL);
		ft_minishell();
	}
	else
	{
		opendir(av[1]);
		if (!errno)
			errno = EISDIR;
		perror(av[1]);
		exit (errno);
	}
	return (_RETURN);
}
