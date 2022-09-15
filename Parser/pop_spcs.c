/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_spcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:29:44 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/09/15 22:37:23 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static t_list	*replace_node(char *slpt[], t_list *mngr, t_list *root)
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
	mngr->prev->next = new;
	mngr->next->prev = ft_lstlast(new);
	ft_lstlast(new)->next = mngr->next;
	return (root);
}

static void	pop_help(char *quot, t_list *mngr, int *start, int *i)
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
				mngr->token[(*start) - 1] = '\003';
		(*i) -= 1;
		(*start) -= 2;
	}
}

static t_list	*pop_spcs(t_list *root)
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
		root = replace_node(ft_split(mngr->token, '\003'), mngr, root);
		mngr = mngr->next;
	}
	return (root);
}

t_list	*pop_spcs_tree(t_list *root)
{
	t_list	*mng;

	mng = root;
	while (mng->symbol == '|')
	{
		mng->left = pop_spcs(mng->left);
		if (mng->right->symbol != '|')
		{
			mng->right = pop_spcs(mng->right);
			return (root);
		}
		mng = mng->right;
	}
	return (pop_spcs(root));
}
