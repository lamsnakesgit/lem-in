#include "libft/libft.h"
#include "lemin.h"
int main()
{
	char **ok;
	char *s = "FILLIT 0909 10";
	ok = ft_strsplit(s, ' ');
	while (*ok)
	{
//		printf("%s\n|% s\n% s\n", *ok);//seg printf spce
		printf("%s\\n|%% s\\n%% s\\n", *ok);
		++ok;
	}
	return 0;
/*
	ok = (char**)lrc->br->content;
	i = 0;
	int r = 0;
	while (ok[r])
	{
		i = 0;
		printf("%s\n", ok[r]);//works
		//	while (ok[r][i])
		//	{
		//		printf("%c\n", ok[r][i]);
		//		++i;
		//	}
		++r;
	}//works
	/ *	while (*ok)
		{
			printf("$%s|\n", *ok);
			++ok;
		}* / //works
	printf("%c \\\\\n", ok[0][0]);//works
	printf("%s\n", *ok);//works
	printf("%s\n|", ok[0]);//lrc->br->content[0]);//, (llrc->br->content)[1], (llrc->br->content)[2]);
/ *SGVF* /	//printf("%s\n|% s\n% s\n", ok[0]);//lrc->br->content[0]);//, (llrc->br->content)[1], (llrc->br->content)[2]);
/ * wrks * /	printf("-%s\n", ok[0]);//lrc->br->content[0]);//, (llrc->br->content)[1], (llrc->br->content)[2]);
/ *SGVF* /	printf("%s\n|% s% s", ok[0]);//lrc->br->content[0]);//, (llrc->br->content)[1], (llrc->br->content)[2]);
	//	printf("%s\n|% s\n% s\n", lrc->br->content[0]);//, (llrc->br->content)[1], (llrc->br->content)[2]);																																														(llrc->br->content)[2]);
*/}
