#include<stdio.h>
#include <algorithm> 
using namespace std;


int main ()
{
	 int round;
	 scanf("%d",&round);
	 while(round--)
	 {
	 	int len,ants,where,mint=0,maxt=0;
	 	scanf("%d %d",&len,&ants);
	 	
	 	while(ants--)
	 	{
		 	scanf("%d",&where);
		 	mint=max(mint,min(where,len-where));
		 	maxt=max(maxt,max(where,len-where));
		
		}
	 	printf("%d %d\n",mint,maxt);
	 }
	 
	 return 0;
}
