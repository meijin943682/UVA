#include<stdio.h>

int main ()
{
	int T, i;
	scanf("%d", &T);
	for(i = 1; i <= T; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		
		if(a % 2 == 0)
			a++;
		if(b % 2 == 0)
			b--;
		
		printf("Case %d: %d\n", i, (a + b) * ((b - a)/2 + 1) / 2);
	}
	return 0;
}