#include<stdio.h>
#include <algorithm>
#include<string.h>

using namespace std;


int main ()
{
	int region[999],m,n,round=1;
	
	while(scanf("%d %d",&m,&n) == 2 && m !=0 && n != 0)
	{
		memset(region,0,sizeof(region));
		printf("Region %d\n",round);
		round++;
		
		for(int i=0;i<(m*n);i++)
			scanf("%d",&region[i]);
		sort(region,region+m*n);
		
		int flood,num=0;
		scanf("%d",&flood);
		
		while(flood >= 0 && num != (m*n))
		{
			flood -= (region[num+1]-region[num])*(num+1)*100;
			num++;
		}
		float persent = num/(float)(m*n)*100, water= region[num]+(flood/(float)(100*(num)));
		printf("Water level is %.2f meters.\n",water);
		printf("%.2f percent of the region is under water.\n\n",persent);
	}
	return 0;
	
}
