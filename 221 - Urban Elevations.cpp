#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
double point[500];
struct building
{
	double x,y,w,d,h;
	int labal;
	
	bool operator < (const building & build) const
	{
		return x < build.x || (x == build.x && y < build.y);
	}
}build[222];

bool cover (int i,double mx)
{
	return build[i].x <= mx && build[i].x+build[i].w >= mx;
}


bool visible (int i,double mx)
{
	if(!cover(i,mx))
		return false;
	for(int k = 0;k<n;k++)
	{
		if(build[k].y < build[i].y && build[k].h >= build[i].h && cover(k,mx))
			return false;
	}
	return true;
}

int main ()
{
	int round=0;
	while(scanf("%d",&n) == 1 && n )
	{
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf%lf", &build[i].x, &build[i].y, &build[i].w, &build[i].d, &build[i].h);
			build[i].labal=i;
			point[i*2]=build[i].x;
			point[i*2+1]=build[i].x+build[i].w;
		}
		
		sort(build,build+n);
		sort(point,point+n*2);
		int m=unique(point,point+n*2) - point ;
		
		if(round++)
			printf("\n");
		printf("For map #%d, the visible buildings are numbered as follows:\n%d",round,build[0].labal+1);
		
		for(int i=1;i<n;i++)
		{
			bool vis=false;
			
			for(int j=0;j<m-1;j++)
			{
				if(visible(i,(point[j]+point[j+1])/2))
				{
					vis = true;
					break;
				}
			}
			if(vis)
				printf(" %d",build[i].labal+1);
		}
		printf("\n");
	}
	return 0;
}

