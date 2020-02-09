
#include "lemin.h"

void			print_l(t_llrc *lrc)
{
	t_list	*l;
	int		i;

	i = 0;
	l = lrc->arrrm[i]->ln;
	while (l && i < lrc->rmi)
	{
		while (l)
		{
			printf("i=%4s|%6s=|%d\n", lrc->arrrm[i]->name_r,
				((t_rooms *)l->content)->name_r,
				((t_rooms *)l->content)->lvl);
			l = l->next;
		}
		printf("\n");
		++i;
		if (i == lrc->rmi)
			break ;
		l = lrc->arrrm[i]->ln;
	}
}

void			printflist(t_list *ln)
{
	t_list	*path;
	int		i;

	i = 0;
	path = ln;
	while (path)
	{
		printf("%s ", ((t_rooms *)path->content)->name_r);
		path = path->next;
	}
	printf("\n");
}

void			printallpaths(t_list *ln)
{
	t_list *path;

	path = ln;
	while (path)
	{
		printflist(path->content);
		path = path->next;
	}
	printf("\n");
}

t_list			*lastpath(t_list **paths, int i)
{
	t_list *ln;

	ln = *paths;
	if (i == 2)
	{
		while (ln && ln->next && ln->next->next && ln->next->next->next)
		{
			ln = ln->next;
		}
	}
	else if (!i)
	{
		while (ln->next)
			ln = ln->next;
	}
	else
	{
		while (ln->next->next)
			ln = ln->next;
	}
	return (ln);
}

void			delpath(t_list **paths, t_list *ln)
{
	t_list *tr;
	t_list *tr2;

	tr = *paths;
	tr2 = NULL;
	while (tr)
	{
		if (tr == ln)
		{
			if (!tr2)
			{
				(*paths) = (*paths)->next;
				free(tr);
			}
			else
			{
				tr2->next = ln->next;
				free(ln);
			}
			return ;
		}
		tr2 = tr;
		tr = tr->next;
	}
}
