#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;

int main ()
{
	int n,target[1010];
	while(scanf("%d", &n) != EOF && n !=0)
	{
		memset(target,0,sizeof(target));
		stack<int> rail;
	
		while(scanf("%d",&target[1]) != EOF && target[1] != 0 ) 
		{
			
			int a=1,b=1,kase=1;
			for(int i=2;i<=n;i++)
				scanf("%d",&target[i]);
			
			while(b <= n)
			{
				if(a == target[b])
				{
					a++;
					b++;
				}
				else if(!rail.empty() && rail.top() == target[b] ) 
				{
					rail.pop();
					b++;
				}
				else if (a <= n)
				{
					rail.push(a);
					a++;	
				}
				else
				{
					kase=0;
					break;
				}
			}
			printf("%s\n",kase ? "Yes":"No");
			memset(target,0,sizeof(target));
		}
		printf("\n");	
	}
	return 0;
}
