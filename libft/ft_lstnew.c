/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:02:23 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/08/18 07:23:11 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*con;	

	con = (t_list *)malloc (sizeof (*con));
	if (!con)
		return (NULL);
	con->content = content;
	con->next = NULL;
	return (con);
}
