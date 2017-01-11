#include<stdio.h>

const char keyboard[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main ()
{
	char input;
	while((input = getchar()) != EOF)
	{
		int i;
		if(input == ' '|| input == '\n')
			printf("%c", input);
		else
		{
			for(i = 0; keyboard[i] != input; i++);
			printf("%c", keyboard[i - 1]);
		}
	}
	return 0;
}
