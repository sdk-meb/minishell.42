/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:31:10 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/22 10:42:58 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Include/minishell.h"

void	ft_minishell()
{
	ft_call_shell(PRIO_USER);
}

// static void	sig()
// {
//  	signal_handler();
// }

int	main(int ac, char *av[], char *env[])
{
	signal_handler();
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
	 	ft_err(ft_strdup(av[1]), errno);
		exit (errno);
	}
	return (_RETURN);
}
