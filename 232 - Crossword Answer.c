#include<stdio.h>
#include<string.h>

char puzzle[10][10];

void search (int nowi, int nowj, int iorj, int r, int c)
{
	printf("%c", puzzle[nowi][nowj]);

	if(iorj == 0)
	{
		if(nowj == c - 1 || puzzle[nowi][nowj + 1] == '*')
			return;
		search(nowi, nowj + 1, 0, r, c);
	}
	else
	{
		if(nowi == r - 1|| puzzle[nowi + 1][nowj] == '*')
			return;
		search(nowi + 1, nowj, 1, r, c);
	}
}
int main ()
{
	int r, c, round = 0;
	while(~scanf("%d", &r) && r != 0)
	{
		if(round != 0)
			printf("\n");
		scanf("%d", &c);
		printf("puzzle #%d:\n", ++round);

		int i, j;
		for(i = 0; i < r; i++)
			scanf("%s", puzzle[i]);

		printf("Across\n");
		int word = 0;
		for(i = 0; i < r; i++)
		{
			for(j = 0; j < c; j++)
			{
				if(puzzle[i][j] != '*' && (i == 0 || j == 0 || puzzle[i - 1][j] == '*' || puzzle[i][j - 1] == '*'))
					word++;
				if(puzzle[i][j] != '*' && (j == 0 || puzzle[i][j - 1] == '*'))
				{
					printf(" %2d.", word);
					search(i , j, 0, r, c);
					printf("\n");
				}
			}
		}
		printf("Down\n");
		word = 0;
		for(i = 0; i < r; i++)
		{
			for(j = 0; j < c; j++)
			{
				if(puzzle[i][j] != '*' && (i == 0 || j == 0 || puzzle[i - 1][j] == '*' || puzzle[i][j - 1] == '*'))
					word++;
				if(puzzle[i][j] != '*' && (i == 0 || puzzle[i - 1][j] == '*'))
				{
					printf(" %2d.", word);
					search(i , j, 1, r, c);
					printf("\n");
				}
			}
		}
	}
	return 0;
}
