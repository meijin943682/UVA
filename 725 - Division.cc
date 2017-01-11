#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int N, input = 0;
	while((~scanf("%d", &N)) && N)
	{
		if(input != 0)
			puts("");
		input++;

		int sol = 0;
		for(int i =  1234; i <= 98765; i++)
		{
			int Dividend = i * N, Divisor = i, num[10];
			if(Dividend > 98765)
				continue;
			bool check = true;
			memset(num, 0, sizeof(num));

			for(int j = 0; j < 5; j++)
			{
				num[Dividend % 10]++, num[Divisor % 10]++;
				Dividend /= 10, Divisor /= 10;
			}

			for(int j = 0; j < 10; j++)
				if(num[j] != 1)
					check = false;
			if(check)
			{
				printf("%d / %05d = %d\n", i * N, i, N);
				sol++;
			}
		}
		if(sol == 0)
			printf("There are no solutions for %d.\n", N);
	}
	return 0;
}
