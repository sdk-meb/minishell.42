/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:19:23 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/02 16:12:32 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	brek_spaces(t_ptr ptr, t_cmd cmd)
{
	int	count;
	int	sp;

	count = -1;
	sp = 0;
	while (cmd && cmd->symbol != 'w')
		cmd = cmd->next;
	if ((ft_strcmp(cmd->type, cmd->token)
			&& cmd->type[0] != '\'' && cmd->type[0] != '\"')
		|| ft_memcmp(cmd->type + 1, cmd->token, ft_strlen(cmd->type) - 2))
	{
		while (ptr[++count])
		{
			if (ptr[count] != ' ' || ptr[count - 1] != ' ')
				ptr[sp++] = ptr[count];
		}
		if (sp && ptr[sp - 1] == ' ')
			sp--;
		ptr[sp] = '\0';
	}
}

static bool	new_line_option(t_cmd cmd, int *i)
{
	static bool	new_line;
	int			cas_e;

	if (i == NULL || !cmd)
		return (new_line);
	while (cmd->arv[++(*i)] && cmd->arv[*i][0] == '-')
	{
		cas_e = 1;
		while (cmd->arv[*i][cas_e] == 'n')
			cas_e++;
		if (cmd->arv[*i][cas_e] || cas_e == 1)
			break ;
		new_line = 1;
	}
	return (new_line);
}

void	echo(t_cmd cmd)
{
	t_cmd	mng;
	int		i[2];

	mng = cmd;
	i[0] = 0;
	new_line_option(mng, &(i[0]));
	while (cmd->arv[i[0]])
	{
		brek_spaces(cmd->arv[i[0]], mng->next);
		write(cmd->out, cmd->arv[i[0]], ft_strlen(cmd->arv[i[0]]));
		if (cmd->arv[++i[0]])
			write(cmd->out, " ", 1);
	}
	if (!new_line_option(NULL, NULL))
		write(cmd->out, "\n", 1);
	close_fd(&(cmd->in), &(cmd->out));
	exit(0);
}
