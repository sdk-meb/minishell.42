/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_chap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:02:02 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/14 22:01:05 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Include/minishell.h"

static void *governor(t_req ord)
{
    static t_heap *tmp;
    static t_heap *glb;

    if ((ord & APPROVED) == APPROVED)
    {
        if (!(glb) && (ord & _SET) == _SET)
        {
            glb = (t_heap *)ft_calloc(sizeof(*glb), 1);
            glb->loc = EMPTY;
            glb->extra = NULL;
            glb->prev = glb;
        }
        if (!glb)
            return (NULL);
        return ((void*) glb);
    }
    if (!tmp && (ord & _SET) == _SET)
    {
            tmp = (t_heap *)ft_calloc(sizeof(*tmp), 1);
            tmp->loc = EMPTY;
            tmp->extra = NULL;
            tmp->prev = tmp;
    }
    if (!tmp)
            return (NULL);
    return ((void*) &tmp);
}

static void    c_merge(void *ptr, int loc, t_req ord)
{
    t_heap        *mnger;

    mnger = (t_heap *)governor(ord | _SET | _GET);
    while (mnger->extra)
        mnger = mnger->extra;
    if (mnger->loc != EMPTY)
    {
        mnger->extra = (t_heap *)ft_calloc(sizeof(*mnger), 1);
        mnger->extra->prev = mnger;
        mnger = mnger->extra;
    }
    mnger->loc = loc;
    mnger->dng_ptr = ptr;
    mnger->extra = NULL;
    while (mnger->prev->extra)
        mnger = mnger->prev;
}

void    c_delete(int dangle, t_req ord)
{
    t_heap        *mnger;
    t_heap       *manager;
    void        *ptr;

    manager = (t_heap *)governor(ord | _SET | _GET);
    mnger = manager;
    while (mnger)
    {
        
    }
}

void    *new_heap(size_t tcase, size_t loc, t_req ord)
{
    void *ptr;

    ptr = ft_calloc(tcase, 1);
    c_merge(ptr, loc, ord);
    return (ptr);
}
