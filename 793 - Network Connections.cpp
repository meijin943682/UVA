#include<stdio.h>
#include<string.h>
#include<algorithm> 

using namespace std;

int pcc[1111111];
bool kase;

int find (int leader)
{
	if(leader == pcc[leader])
		return leader;
	//printf("leader %d\n",leader);
	return (pcc[leader]=find(pcc[leader]));
	
} 

void connect (int c1,int c2)
{
	int boss1=find(c1);
	int boss2=find(c2);
	
	if(boss1 <= boss2)
	{
		pcc[boss2]=boss1;
		//printf("c1 %d c2 %d pcc[c1] %d pcc[c2] %d\n",c1,c2,pcc[c1],pcc[c2]);
	}
	else
		pcc[boss1]=boss2;
	return ;
}

bool question (int c1, int c2)
{
	if(find(c1) == find(c2))
		return true;
	return false;
}

int main ()
{
	int round;
	scanf("%d",&round);
	
	while(round--)
	{
		for(int i=0;i<=1000000;i++)
			pcc[i]=i;
	
		int pc,yes=0,no=0;	
		scanf("%d",&pc);
		getchar();
		char methon [30];
		
		while(fgets(methon ,30 ,stdin))
		{
			if(methon[0] == '\n')
				break;
				
			int pc1,pc2;
			sscanf(&methon[1],"%d %d",&pc1,&pc2);
			//fprintf(stderr,"%d %d\n",pc1,pc2);
				
			if(methon[0]  == 'c')
				connect(pc1,pc2);	
			else
			{
				if(question(pc1,pc2))
					yes++;
				else
					no++;
			}					
			memset(methon,0,sizeof(methon));
		}
		if(round != 0)	
			printf("%d,%d\n\n",yes,no);
		else
			printf("%d,%d\n",yes,no);
	}
	return 0;
}
