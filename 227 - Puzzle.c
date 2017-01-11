#include<string.h>
#include<stdio.h>
#include<ctype.h>

int main ()
{
	char puzzle[5][6];
	int round = 0;
	while(gets(puzzle[0]))
	{
		int i, j, spaceI, spaceJ;
		if(!strcmp(puzzle[0], "Z"))
			break;

		if(round != 0)
			printf("\n");

		printf("Puzzle #%d:\n", ++round);
		for(i = 1; i < 5; i++)
			gets(puzzle[i]);

		for(i = 0; i < 5; i++)
		{
			for(j = 0; j < 5; j++)
			{
				if(puzzle[i][j] == ' ' || puzzle[i][j] == '\0')
				{
					spaceI = i;
					spaceJ = j;
				}
			}
		}

		char oper;
		int flag = 1;
		while(oper = getchar())
		{
			if(oper == '0')
				break;
			else if(oper == '\n')
				continue;

			switch(oper)
			{
				case 'A':
					if(spaceI != 0)
					{
						puzzle[spaceI][spaceJ] = puzzle[spaceI - 1][spaceJ];
						puzzle[--spaceI][spaceJ] = ' ';
					}
					else
						flag = 0;
					break;
				case 'B':
					if(spaceI != 4)
					{
						puzzle[spaceI][spaceJ] = puzzle[spaceI + 1][spaceJ];
						puzzle[++spaceI][spaceJ] = ' ';
					}
					else
						flag = 0;
					break;
				case 'L':
					if(spaceJ != 0)
					{
						puzzle[spaceI][spaceJ] = puzzle[spaceI][spaceJ - 1];
						puzzle[spaceI][--spaceJ] = ' ';
					}
					else
						flag = 0;
					break;
				case 'R':
					if(spaceJ != 4)
					{
						puzzle[spaceI][spaceJ] = puzzle[spaceI][spaceJ + 1];
						puzzle[spaceI][++spaceJ] = ' ';
					}
					else
						flag = 0;
					break;
				default:
					flag = 0;
					break;
			}
		}
		oper = getchar();

		if(flag)
		{
			for(i = 0; i < 5; i++)
				printf("%c %c %c %c %c\n", puzzle[i][0], puzzle[i][1], puzzle[i][2], puzzle[i][3], puzzle[i][4]);
		}
		else
			printf("This puzzle has no final configuration.\n");
	}

	return 0;
}
