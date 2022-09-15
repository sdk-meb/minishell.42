#include "../Include/minishell.h"

t_list *pop_spcs(t_list *root)
{
	t_list *mngr;
	int i, start = 0, end;
	char **new;

	mngr = root;
	while (mngr)
	{
		i = -1;
		while (mngr->type[++i])
		{
			if (ft_is_quote(mngr->type[i]))
				i = ft_get_next_quote(i, mngr->type);
			if (ft_is_quote(mngr->type[i]) && mngr->type[i + 1] == '$')
				i++;
			if (mngr->type[i] == '$')
			{
				start += (i++ - start);
				end = ft_strlen(ft_get_env(mngr->type, &i)) + start--;
				while (++start < end)
					if (mngr->token[start] == ' ' && printf("%c",mngr->token[start]))
						mngr->token[start] = '`';
				printf("\n");
			}
		}
		new = ft_split(mngr->token, '`');
		while (new && *new)
			printf("%s\n", *new++);
		mngr = mngr->next;
	}
	return (root);
}