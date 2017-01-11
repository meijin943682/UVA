#include<stdio.h>

int main ()
{
	int number1, number2;
	while(scanf("%d%d", &number1, &number2) != EOF && (number1 || number2))
	{
		int carry = 0, taken = 0;
		while(number1 || number2)
		{
			taken = number1 % 10 + number2 % 10 + taken, taken /= 10;
			number1 /= 10, number2 /= 10;
			
			if(taken)
				carry++;
		}
		if(carry > 1)
			printf("%d carry operations.\n", carry);
		else if(carry == 1)
			printf("1 carry operation.\n");
		else
			printf("No carry operation.\n");
	}
	return 0;
}