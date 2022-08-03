/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:26:42 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/03 01:37:59 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../lib/shell.h"

void    set_evar(_head name, _head val)
{
    (void)name;
    (void)val;
    return ;
}

t_var** save_exp(t_env env)
{
    static t_var *exp;

    if (env)
    {
        exp = (t_var *) malloc(sizeof(exp));
        (exp)->name = NULL;
        (exp)->val = "pdosja";
        (exp)->nextvr = NULL;
        (exp)->env = env;
    }
    return (&exp);
}

t_env   ft_export(t_req req)
{
 //   t_env   env;
    t_var   **envv;
    
    envv = save_exp(NULL);
    if (req == _GET)
        return NULL;
    return NULL;
}
