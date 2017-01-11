#include<stdio.h>
#include<string.h>

char code[8][1<<8];

int readchar ()
{
	for(;;)
	{
		char ch = getchar();
		if(ch != '\n' && ch != '\r')
			return ch;
	}
}
int readint (int c)
{
	int k=0;
	while(c--)
		k = k*2 + readchar()-'0';
	return k;
}

int readcode()
{
	memset(code,0,sizeof(code));
	code[1][0] = readchar();
	for(int i=2;i <= 7;i++)
	{
		for(int j=0; j < (1<<i)-1; j++) 
		{
			int ch = getchar ();
			if(ch == EOF)
				return 0;
			if(ch == '\r' || ch == '\n')
				return 1;
			code[i][j] = ch;
		}
	}
	return 1;
}


int main ()
{	
	while(readcode()) 
	{
		for(;;)		
		{
			int len=readint(3);
			if(len == 0)
				break;
			for(;;)
			{
				int num=readint(len);
				if(num == (1<<len)-1)
					break;
				putchar(code[len][num]);
			}
		}
		putchar('\n');
	} 
	return 0;
}
