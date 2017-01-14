#include<cstdio>
#include<cstring>

int main()
{
	int D, I, Case;
	while(scanf("%d", &Case) == 1 && Case != -1)
	{
		while(Case--)
		{
			scanf("%d %d", &D, &I);
			int now = 1;
			for(int i = 0; i < D - 1; i++)
			{
				if(I % 2)
				{
					now = now * 2;
					I = (I + 1) / 2;
				}
				else
				{
					now = now * 2 + 1;
					I /= 2;
				}
			}
			printf("%d\n", now);
		}
	}
	return 0;
}
