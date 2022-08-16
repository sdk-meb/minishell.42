/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_chap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:02:02 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/15 22:31:12 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Include/minishell.h"


static void *get_gover(void)
{
    t_heap *mng;

    mng = (t_heap *)ft_calloc(sizeof(*mng), 1);
    if (!mng)
        return (NULL);
    mng->prev = mng;
    return ((void*) mng);
}

static void *governor(t_req ord)
{
    static void *glb;
    static void *tmp;

    if ((ord & APPROVED) == APPROVED)
    {
        if (!glb && (ord & _SET) == _SET)
            glb = get_gover();
        else if (!glb || (ord & EMPTY) == EMPTY)
            return (NULL);
        return (glb);
    }
    else if ((ord & TEMPORARY) == TEMPORARY)
    {
        if (!tmp && (ord & _SET) == _SET)
            tmp = get_gover();
        else if (!tmp || (ord & EMPTY) == EMPTY)
            return (NULL);
        return (tmp);
    }
    return (NULL);
}

static void    c_merge(void *ptr, t_req ord)
{
    t_heap        *mnger;
    t_heap         *manager;

    return ;
    manager = (t_heap *)governor(ord | _SET | _GET);
    mnger = manager;printf("%p\n",mnger);
    while (mnger->extra){
        mnger = mnger->extra;}
    if (mnger->dng_ptr)
    {
        mnger->extra = (t_heap *)ft_calloc(sizeof(*mnger), 1);
        mnger->extra->prev = mnger;
        mnger = mnger->extra;
        manager->prev = mnger;
    }
    mnger->dng_ptr = ptr;
    mnger->extra = NULL;
}

static void dlt(t_heap *mnger)
{
    if (!mnger)
        return ;
    dlt(mnger->extra);
    free(mnger->dng_ptr);
    free(mnger);
}

void    c_delete(t_req ord)
{
    t_heap       *manager;
    
    return ;
    if (ord != APPROVED && ord != TEMPORARY)
        return ;
    manager = (t_heap *)governor(ord | _SET | _GET);
    dlt(manager);
    governor(ord | EMPTY);
}

void    *new_heap(size_t tcase, t_req ord)
{
    void *ptr;
    if (ord != APPROVED && ord != TEMPORARY)
        return (NULL);
    ptr = ft_calloc(tcase, 1);
    c_merge(ptr, ord);
    return (ptr);
}
