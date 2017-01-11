#include<stdio.h>

int main ()
{
	int N;
	scanf("%d", &N);

	while(N--)
	{
		int train[50], L, i, j, S = 0;
		scanf("%d", &L);

		for(i = 0; i < L; i++)
			scanf("%d", &train[i]);

		for(i = 0; i < L - 1; i++)
		{
			for(j = 0; j < L - i -1; j++)
			{
				if(train[j] > train[j + 1])
				{
					int change = train[j];
					train[j] = train[j + 1];
					train[j + 1] = change;
					S++;
				}
			}
		}
		printf("Optimal train swapping takes %d swaps.\n", S);
	}
	return 0;
}
