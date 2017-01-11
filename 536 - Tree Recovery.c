#include<stdio.h>
#include<string.h>


char* travel(char* Pre, char* In, int size)
{
	int i;
	char* left, *right;
	for(i = 0; i < size; i++)
	{
		if(*Pre == *(In + i))
		{
			left = travel(Pre + 1, In, i);
			right = travel(Pre + i + 1, In + i + 1, size - i - 1);
			printf("%c", *Pre);
			return Pre;
		}
	}
	return NULL;
}

int main ()
{
	char Pre[100], In[100], Post[100];
	
	while(scanf("%s %s", Pre, In) == 2)
	{
		memset(Post, '\0', sizeof(Post));
		int size = strlen(Pre);
		
		travel(Pre, In, size);
		printf("\n");
	}
	return 0;
}