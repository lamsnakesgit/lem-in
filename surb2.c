#include "lemin.h"

void    sur(t_mas	mas, t_llrc *llrc, t_list **paths)
{
	mas.i = 0;
	surb3(((t_list*)mas.tr->content)->next, ((t_list*)mas.ln->content)->next, &mas);
	mas.i += cross_path(paths, (t_list *) mas.m0, (t_list *) mas.m1, 0);
	mas.i += cross_path(paths, (t_list *) mas.m2, (t_list *) mas.m3, 1);
	llrc->plensum -= ((t_list*)mas.ln->content)->content_size;
	llrc->psum -= 1;
	delpath(paths, mas.ln);
	if (!path_cmp(((t_list*)mas.tr->content)->content_size, llrc, mas.i))
	{
		mas.ln = lastpath(paths, 1);
		free(mas.ln->next);
		mas.ln->next = NULL;
		mas.ln = lastpath(paths, 1);
		free(mas.ln->next);
		mas.ln->next = NULL;
	}
	else
	{
		llrc->plensum += mas.i - ((t_list*)mas.tr->content)->content_size;
		llrc->psum += 1;
		delpath(paths, mas.tr);
	}
	mas.ln = lastpath(paths, 2);
	mas.tr = (*paths);
}
int				surb(t_list **paths, t_llrc *llrc)
{
	t_mas	mas;

	mas.i = -1;
	mas.tr = (*paths);
	mas.ln  = lastpath(paths, 0);
	mas.ln2 = mas.ln;
	if (mas.ln == mas.tr)
		return (0);
	while (mas.ln)
	{
		while (mas.tr->next && mas.tr != mas.ln)
		{
			if (surb2(((t_list*)mas.ln->content)->next, ((t_list*)mas.tr->content)->next, &mas))
			{
				mas.i = 0;
				surb3(((t_list*)mas.tr->content)->next, ((t_list*)mas.ln->content)->next, &mas);
				mas.i += cross_path(paths, (t_list *) mas.m0, (t_list *) mas.m1, 0);
				mas.i += cross_path(paths, (t_list *) mas.m2, (t_list *) mas.m3, 1);
				llrc->plensum -= ((t_list*)mas.ln->content)->content_size;
				llrc->psum -= 1;
				delpath(paths, mas.ln);
				if (!path_cmp(((t_list*)mas.tr->content)->content_size, llrc, mas.i))
				{
					mas.ln = lastpath(paths, 1);
					free(mas.ln->next);
					mas.ln->next = NULL;
					mas.ln = lastpath(paths, 1);
					free(mas.ln->next);
					mas.ln->next = NULL;
				}
				else
				{
					llrc->plensum += mas.i - ((t_list*)mas.tr->content)->content_size;
					llrc->psum += 1;
					delpath(paths, mas.tr);
				}
				mas.ln = lastpath(paths, 2);
				mas.tr = (*paths);
				break;
			}
			mas.tr = mas.tr->next;
		}
		mas.ln = mas.ln->next;
	}
	if (mas.i == -1)
	{
		if (path_cmp2(llrc, ((t_list*)mas.ln2->content)->content_size))
		{
			llrc->psum -= 1;
			llrc->plensum -= ((t_list*)mas.ln2->content)->content_size;
			delpath(paths, mas.ln2);
			return (1);
		}
	}
	return (0);// if i = 0 то не пересек
}