#include "../Include/minishell.h"

t_list *pop_spcs(t_list *root)
{
	t_list *mngr;
	char quot = 0;
	int i, start, end;
	char **new;

	mngr = root;
	while (mngr)
	{
		i = -1;
		start = -1
		while (mngr->type[++i] && mngr->token[++start])
		{
			if (ft_is_quot(mngr->type[i]) && quot == 0)
			{
				quot == mngr->type[i];
				i++;
			}
			else if (quot == mngr->type[i])
			{
				quot == 0;
				i++;
			}
			if (quot == 0 && mngr->type[i] == '$')
			{
				end = ft_strlen(ft_get_env(mngr->type, &i)) + start--;
				while (++start < end)
					if (mngr->token[start] == ' ' && printf("%c",mngr->token[start]))
						mngr->token[start] = '`';
			}
		}
		new = ft_split(mngr->token, '`');
		while (new && *new)
			printf("%s\n", *new++);
		mngr = mngr->next;
	}
	return (root);
}