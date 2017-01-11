#include <cstdio>
#include <cstring>
using namespace std;

char search(int ch, int m, char DNA[][1111], int &distance)
{
	int ACGT[4], i;
	char table[6] = "ACGT";
	memset(ACGT, 0, sizeof(ACGT));

	for(i = 0; i < m; i++)
	{
		switch(DNA[i][ch])
		{
			case 'A':
				ACGT[0]++;
				break;
			case 'C':
				ACGT[1]++;
				break;
			case 'G':
				ACGT[2]++;
				break;
			case 'T':
				ACGT[3]++;
				break;
		}
	}
	int num = ACGT[0], bigch = 0;
	for(i = 1; i < 4; i++)
	{
		if(ACGT[i] > num)
		{
			num = ACGT[i];
			bigch = i;
		}
	}
	for(i = 0; i < 4; i++)
	{
		if(i != bigch)
			distance += ACGT[i];
	}
	return table[bigch];
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int m, n, i, distance = 0;
		scanf("%d %d", &m, &n);
		char DNA[55][1111];
		for(i = 0; i < m; i++)
			scanf("%s", DNA[i]);

		for(i = 0; i < n; i++)
		{
			printf("%c", search(i, m, DNA, distance));
		}
		printf("\n%d\n", distance);
	}
	return 0;
}
