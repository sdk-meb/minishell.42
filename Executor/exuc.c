/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exuc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:30:41 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/13 22:41:06 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Include/minishell.h"


void    ex_bin(t_path p_file)
{
    execve(p_file, NULL, NULL);
}

void sh_exece(t_cmd *cmd)
{
    t_cmd h;
    printf("\n_EX_\n");
    h = *cmd;
    A:
        while (h)
        {
            printf("next %s", h->token);
            if (!h->next)
                break ;
            h = h->next;
        }
        h = h->right;
    goto A;
}
