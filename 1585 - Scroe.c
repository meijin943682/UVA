#include <stdio.h>
#include <string.h>

int main()
{
	int len, input;
	char OX[88];
	scanf("%d", &input);

	while(input--)
	{
		scanf("%s", OX);
		len = strlen(OX);
		int score = 0, count = 0, i;
		for(i = 0; i < len; i++)
		{
			if(OX[i] == 'O')
			{
				count++;
				score += count;
			}
			else
				count = 0;
		}
		printf("%d\n", score);
	}

	return 0;
}
