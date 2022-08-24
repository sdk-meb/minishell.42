/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:31:10 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/24 01:15:37 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/minishell.h"

void	ft_minishell(void)
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
