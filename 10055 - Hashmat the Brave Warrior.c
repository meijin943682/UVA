#include <stdio.h>

int main ()
{
	long long int soldiers,opp;
	while(scanf("%lld%lld",&soldiers,&opp) != EOF)
	{	
		if (soldiers < opp)
			printf("%lld\n",opp - soldiers);
		else
			printf("%lld\n",soldiers - opp);
	}
	return 0;
}