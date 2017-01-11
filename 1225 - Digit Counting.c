#include<stdio.h>
#include<string.h>

void count (int num, int digit[])
{
	int i;
	for(i = 1; i <= num; i++)
	{
		int now = i;
		while(now)
		{
			digit[now % 10]++;
			now /= 10;
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int num, digit[10], i;
		for(i = 0; i < 10; i++)
			digit[i] = 0;
		scanf("%d", &num);
		count(num, digit);
		for(i = 0; i < 9; i++)
			printf("%d ", digit[i]);
		printf("%d\n", digit[9]);
	}
	return 0;
}
