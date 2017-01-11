#include<stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int sum = 0, f;
		scanf("%d", &f);
		while(f--)
		{
			int size, animal, environment;
			scanf("%d%d%d", &size, &animal, &environment);
			sum += size * environment;
		}
		printf("%d\n", sum);
	}
	return 0;
}