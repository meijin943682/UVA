#include <stdio.h>

int main ()
{
	int from, to;
	while(scanf("%d%d", &from, &to) == 2)
	{
		int a = from, b = to, i;
		if(from > to)
		{
			a = to;
			b = from;
		}
		
		int max = 0;
		for(i = a; i <= b; i++)
		{
			int now = i, length = 1;
			while(now != 1)
			{
				length++;
				if(now % 2 == 1)
					now = now * 3 + 1;
				else 
					now /= 2;
			}
			
			if(max < length)
				max = length;
		}
		printf("%d %d %d\n", from, to, max);
	}
	return 0;
}
