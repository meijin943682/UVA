#include <stdio.h>
#include <string.h>


int main ()
{
	char s[111111] = {0}, t[111111] = {0};
	while(scanf("%s %s", s, t) != EOF)
	{
		int len_s = strlen(s), len_t = strlen(t), i, j;
		for(i = 0, j = 0; i < len_t && j < len_s; i++)
			if(t[i] == s[j])
				j++;

		if(j == len_s)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
