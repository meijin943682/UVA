#include <stdio.h>
#include <string.h>

int main ()
{
	char input;
	while((input = getchar()) != EOF)
	{
		if(input == '\n')
			printf("\n");
		else
			printf("%c",input - 7);
	}
	return 0;
}