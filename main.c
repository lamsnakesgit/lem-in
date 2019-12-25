#include "libft/libft.h"
#include <stdio.h>
int main()
{
char *s = "okrm 1";// 2";
char **sp;
char **ss;
sp = ft_strsplit(s, ' ');
ss = sp;
while (*sp)
{
printf("%s\n", *sp);
free(*sp);
++sp;
}
free (ss);//(sp);
ft_putstr("FUKinfuk");
return(0);
}
