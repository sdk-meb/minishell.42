/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:31:10 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/23 13:47:28 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Include/minishell.h"

void	ft_minishell()
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
	 	ft_err(ft_strdup(av[1]), errno);
		exit (errno);
	}
	return (_RETURN);
}
