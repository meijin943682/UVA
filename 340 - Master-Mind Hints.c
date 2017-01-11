#include <stdio.h>

int main ()
{
	int num_pwd, pwd[1000], pwd1to9[10], input[1000], i, game = 0;	
	while(scanf("%d", &num_pwd) != EOF && num_pwd != 0)
	{
		game++;
		printf("Game %d:\n", game);

		for(i = 0; i < 10; i++)
			pwd1to9[i] = 0;

		for(i = 0; i < num_pwd; i++)
		{
			scanf("%d", &pwd[i]);
			pwd1to9[pwd[i]]++;
		}
		while(1)
		{
			int condition = 0, A = 0, B = 0, input1to9[10];
			for(i = 0; i < 10; i++)
				input1to9[i] = 0;

			for(i = 0; i < num_pwd; i++)
			{
				scanf("%d", &input[i]);
				input1to9[input[i]]++;
				if(input[i] == 0)
					condition++;
				else if(input[i] == pwd[i])
					A++;
			}
			if(condition == num_pwd)
				break;
			else
			{
				for(i = 1; i < 10; i++)
				{
					if(pwd1to9[i] > input1to9[i])
						B += input1to9[i];
					else	
						B += pwd1to9[i];
				}
				printf("    (%d,%d)\n", A, B - A);
			}
		}
	}
	return 0;
}
