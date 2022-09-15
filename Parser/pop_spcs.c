/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_spcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:29:44 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/15 18:05:17 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void check_llink(char *str, t_list *mng)
{
	printf("start     %s", str);
	while (mng->next)
	{
		printf("+++");
		mng = mng->next;
	}
	while (mng->prev)
	{
		printf("+++");
		mng = mng->prev;
	}
	printf("end      %s", str);
	sleep(2);
}

t_list	*replace_node(char *slpt[], t_list *mngr, t_list *root)
{
	t_list	*new;

	if (!slpt || !slpt[0] || !slpt[1])
		return (root);
	new = ft_create_list_for_tockens(slpt);
	if (!root->next)
		return (new);
	if (mngr == root)
	{
		mngr->next->prev = ft_lstlast(new);
		ft_lstlast(new)->next = mngr->next;
		return (new);
	}
	if (mngr == ft_lstlast(root))
	{
		mngr->prev->next = new;
		new->prev = mngr->prev;
		return (root);
	}
	new->prev = mngr->prev;
	ft_lstlast(new)->next = mngr->next;
	mngr->prev->next = new;
	mngr->next->prev = ft_lstlast(new);
	return (root);
}

void	pop_help(char *quot, t_list *mngr, int *start, int *i)
{
	int	end;

	if (ft_is_quote(mngr->type[(*i)]) && (*quot) == 0)
		(*quot) = mngr->type[(*i)++];
	if ((*quot) == mngr->type[(*i)])
		(*quot) = 0 * (*i)++;
	if ((*quot) == 0 && mngr->type[(*i)] == '$')
	{
		end = ++(*i);
		while (!is_spc(mngr->type[(*i)]))
			(*i)++;
		end = ft_strlen(get_env(ft_substr(mngr->type, end, (*i) - end)));
		while ((*start)++, end-- > 0)
			if (mngr->token[(*start) - 1] == ' ')
				mngr->token[(*start) - 1] = '`';
		(*i) -= 1;
		(*start) -= 2;
	}
}

t_list	*pop_spcs(t_list *root)
{
	t_list	*mngr;
	char	quot;
	int		i;
	int		start;

	mngr = root;
	while (mngr)
	{
		i = -1;
		start = -1;
		quot = 0;
		while (start++, mngr->type[++i])
			pop_help(&quot, mngr, &start, &i);
		printf("[%s]\n", mngr->token);
		root = replace_node(ft_split(mngr->token, '`'), mngr, root);
		mngr = mngr->next;
	}
	exit(0);
	return (root);
}
