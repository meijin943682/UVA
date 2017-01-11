#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main ()
{
	char input;
	bool quotes = false;
	while(1)
	{
		input = getchar();
		if(input == EOF)
			break;
		if (input == '\"' && quotes == false)
		{
			printf("``");
			quotes = true;
		}
		else if (input == '\"' && quotes == true)
		{
			printf("''");
			quotes = false;
		}
		else
			printf("%c",input);
	}
	return 0;
}