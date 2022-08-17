/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:31:10 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/17 13:34:53 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Include/minishell.h"

void	ft_minishell()
{
	//signal_handler();
	//ft_call_shell();
}

int	main(int ac, char *av[], char *env[])
{
	(void)env;
	(void)av;

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
