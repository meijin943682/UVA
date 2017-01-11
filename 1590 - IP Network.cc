#include<cstdio>
#include<cstring>
using namespace std;



int main ()
{
	int n;
	while(~scanf("%d", &n))
	{
		char input[50];
		int num[1111][4], IP[4], subNetwork[4];
		memset(num, 0, sizeof(num));
		memset(IP, 0, sizeof(IP));
		memset(subNetwork, 0, sizeof(subNetwork));

		for(int i = 0; i < n; i++)
		{
			scanf("%s", input);
			sscanf(input, "%d.%d.%d.%d", &num[i][0], &num[i][1], &num[i][2], &num[i][3]);
		}

		bool same = true;
		for(int i = 0; i < 4; i++)
		{
			for(int bit = 7; bit >= 0; bit--)
			{
				bool cmp = (num[0][i] >> bit) & 1;
				for(int k = 0; k < n && same; k++)
					same &= (cmp == ((num[k][i] >> bit) & 1));
				
				if(same)
				{
					IP[i] = (IP[i] << 1) + ((num[0][i] >> bit) & 1);
					subNetwork[i] = (subNetwork[i] << 1) + 1;
				}
				else
				{
					IP[i] <<= 1;
					subNetwork[i] <<= 1;
				}
			}
		}
		printf("%d.%d.%d.%d\n", IP[0], IP[1], IP[2], IP[3]);
		printf("%d.%d.%d.%d\n", subNetwork[0], subNetwork[1], subNetwork[2], subNetwork[3]);
	}
	return 0;
}
