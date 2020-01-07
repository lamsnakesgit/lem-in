#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *s1 = "ABC";
	char *s2 = "ABC";
	s1 = (char *)malloc(sizeof(char) * 4);
	s2 = (char *)malloc(sizeof(char) * 4);
	s1 = "ABC";
	s2 = "ABC";
/*	int i = 0;
		s1[0] = 'A';
		s1[1] = 'B';
		s1[2] = 'C';
		s2[0] = 'A';
		s2[1] = 'B';
		s2[2] = 'C';
		s2[3] =0;
		s1[3]=0;
*/	printf("1 %p %s\n2 %p %s\n", s1, s1, s2,s2);
	printf("s1=%c|s2=%c|", s1[3], s2[3]);
	if (s1 == s2)
		printf("\nT");
	return 0;
}
