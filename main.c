/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:31:10 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/13 13:01:57 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Include/minishell.h"

int	main(int ac, char *av[], char *env[])
{
	(void)env;
	(void)av;
	if (ac == 1)
		ft_call_shell();
	// else
	// {
	// 	opendir(av[1]);
	// 	if (!errno)
	// 		errno = EISDIR;
	// 	ft_err(ft_strdup(av[1]), ERRMSG);
	// 	exit (errno);
	// }
	return (_RETURN);
}
