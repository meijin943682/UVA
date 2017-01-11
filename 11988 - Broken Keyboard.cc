#include<cstdio>
#include<cstring>

int main()
{
	int cur, last, next[111111];
	char str[111111];
	while(scanf("%s", str + 1) == 1)
	{
		int n = strlen(str + 1);
		last = 0, cur = 0, next[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			if(str[i] == '[')
				cur = 0;
			else if(str[i] == ']')
				cur = last;
			else
			{
				next[i] = next[cur];
				next[cur] = i;
				if(cur == last)
					last = i;
				cur = i;
			}
		}
		for(int i = next[0]; i != 0; i = next[i])
			printf("%c", str[i]);
		printf("\n");
	}
	return 0;
}
