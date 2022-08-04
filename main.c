/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:31:10 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/03 14:06:41 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lib/shell.h"

int	main(int ac, t_av av, t_env env)
{
	if (ac == 1)
		ft_minishell(env);
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
