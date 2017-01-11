#include <stdio.h>
#include <math.h>
#include <string.h>

int main ()
{
	char str1[222], str2[222];
	memset(str1, 0, sizeof(str1));
	memset(str2, 0, sizeof(str2));

	while(scanf("%s %s", str1, str2) == 2)
	{
		int i, j, x, y;
		int len1 = strlen(str1), len2 = strlen(str2);
		for(i = 0; i < len1; i++)
		{
			for(j = 0; j < len2; j++)
				if((int)(str1[j + i] + str2[j]) > 99)
					break;
			if(j == len2)
				break;
		}
		x = (len2 + i > len1) ? (len2 + i) : len1;

		for(i = 0; i < len2; i++)
		{
			for(j = 0; j < len1; j++)
				if((int)(str2[j + i] + str1[j]) > 99)
					break;
			if(j == len1)
				break;
		}
		y = (len1 + i > len2) ? (len1 + i) : len2;
		printf("%d\n", (x < y) ? x : y);
		
		memset(str1, 0, sizeof(str1));
		memset(str2, 0, sizeof(str2));
	}
	return 0;
}
