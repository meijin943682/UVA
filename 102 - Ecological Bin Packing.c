#include<stdio.h>

int main ()
{
	int bottle[3][3], taken[6];
	const char ans[6][5] = {{"BCG"}, {"BGC"}, {"CBG"}, {"CGB"}, {"GBC"}, {"GCB"}};
	
	while(scanf("%d", &bottle[0][0]) != EOF)
	{
		int i, j, mintaken, min = 0, total = 0;
		scanf("%d%d", &bottle[0][1], &bottle[0][2]);
		total = bottle[0][0] + bottle[0][1] + bottle[0][2];
		for(i = 1; i < 3; i++)
		{
			for(j = 0; j < 3; j++)
			{
				scanf("%d", &bottle[i][j]);
				total += bottle[i][j];
			}
		}
		taken[0] = total - bottle[0][0] - bottle[1][2] - bottle[2][1];
		taken[1] = total - bottle[0][0] - bottle[1][1] - bottle[2][2];
		taken[2] = total - bottle[0][2] - bottle[1][0] - bottle[2][1];
		taken[3] = total - bottle[0][2] - bottle[1][1] - bottle[2][0];
		taken[4] = total - bottle[0][1] - bottle[1][0] - bottle[2][2];
		taken[5] = total - bottle[0][1] - bottle[1][2] - bottle[2][0];
		
		mintaken = taken[0];
		for(i = 1; i < 6; i++)
		{
			if(mintaken > taken[i])
			{
				mintaken = taken[i];
				min = i;
			}	
		}
		
		printf("%s %d\n", ans[min], mintaken);
	}
	return 0;
}