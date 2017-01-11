#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int less (char* string, int compare, int now)
{
	int len = strlen(string), i;
	for(int i = 0; i < len; i++)
		if(string[(compare + i) % len] != string[(now + i) % len])
			return string[(compare + i) % len] < string[(now + i) % len];
	return 0;
}

int main ()
{
	int T;
	char string[111];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", string);
		int ans = 0, len = strlen(string), i;
		for(i = 1; i < len; i++)
			if(less(string, i, ans))
				ans = i;
		for(i = 0; i < len; i++)
			putchar(string[(i + ans) % len]);
		putchar('\n');
	}
	return 0;
}
