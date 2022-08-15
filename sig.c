/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:11:36 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/13 22:47:43 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Include/minishell.h"

/* signal, sigaction, sigemptyset, sigaddset, kill */

void    sa_sig(int sig)
{
    static unsigned short shild;

    if (sig == NEWCHLD)
        shild++;
    else if (sig == SIGINT)
    {
        printf("\n");
        errno = 130;
        ft_call_shell();
    }
    else if (sig == SIGQUIT)
    {
        errno = 131;
        ft_call_shell();/*  prompt !! */
    }
}

void    signal_handler()
{
    struct sigaction act;
    struct sigaction oact;

    sigemptyset(&(act.sa_mask));
    sigaddset(&(act.sa_mask), SA_USERSPACE_MASK);
    act.sa_handler = sa_sig;

    sigaction(SIGINT, &act, &oact);
    sigaction(SIGQUIT, &act, &oact);
}