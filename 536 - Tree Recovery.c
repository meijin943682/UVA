#include<stdio.h>
#include<string.h>


void travel(char* Pre, char* In, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		if(Pre[0] == In[i])
		{
			travel(Pre + 1, In, i);
			travel(Pre + i + 1, In + i + 1, size - i - 1);
			printf("%c", Pre[0]);
			return;
		}
	}
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
