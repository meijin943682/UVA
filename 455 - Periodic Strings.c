#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isPeriod(int period, char input[])
{
	int i, j, len = strlen(input);
	for(i = 0; i < period; i++)
	{
		for(j = i + period; j < len; j += period)
			if(input[i] != input[j])
				return false;
			
	}
	return true;
}

int main ()
{
	int T, i;
	scanf("%d", &T);
	for(i = 0; i < T; i++)
	{
		if(i != 00)
			printf("\n");
		char input[80];
		scanf("%s", input);
		int len = strlen(input), period;

		for(period = 1; period <= len; period++)
		{
			if(len % period == 0 && isPeriod(period, input))
			{
				printf("%d\n", period);
				break;
			}
		}
	}
	return 0;
}
