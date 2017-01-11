#include<stdio.h>
#include<string.h>

int main ()
{
	int num1, num2;
	int quot_int, quot_float[5000], cycle[5000];
	bool remainder[33333];
	
	while(scanf("%d %d",&num1,&num2) != EOF)
	{
		int ans1 = num1, ans2 = num2;
		memset(quot_float, 0, sizeof(quot_float));
		memset(remainder, 0, sizeof(remainder));
		
		int find = 0, n = 0, len = 0;
		quot_int = num1 / num2;
		num1 %= num2;
		
		while(find == 0)
		{
			if(remainder[num1] == true)
			{
				len = n-cycle[num1];
				find= 1;
				break;
			}
			else
			{	
				remainder[num1] = true;	
				cycle[num1] = n;
			}
			num1 *= 10;
			quot_float[n] = num1/num2;
			num1 =num1 % num2;
			n++; 
		}
		
		printf("%d/%d = %d.",ans1,ans2,quot_int);
		for(int i = 0; i < n; i++)
		{
			if(i == cycle[num1])
				printf("(");
			if(i == 50)
			{
				printf("...");
				break;
			}
			printf("%d",quot_float[i]);
		}
		printf(")\n");
		printf("   %d = number of digits in repeating cycle\n\n",len);
	}
	return 0;
} 
