#include <stdio.h>
#include <string.h>
#define Max_Num 102000

int main ()
{
	int table[Max_Num], x, y, i;
	memset(table, 0, Max_Num);

	for(i = 1; i < 100000; i++)
	{
		x = i, y = i;
		while(x > 0)
		{
			y += x % 10;
			x /= 10;
		}

		if(table[y] == 0 || i < table[y])
			table[y] = i;
	}	
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int input;
		scanf("%d", &input);
		printf("%d\n", table[input]);
	}

	return 0;
}
