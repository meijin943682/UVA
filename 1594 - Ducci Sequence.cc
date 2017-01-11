#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;
int Ducci[20], Num;

bool check()
{
	for(int i = 0; i < Num; i++)
		if(Ducci[i] != 0)
			return false;
	return true;
}

void next()
{
	int tmp[20];
	for(int i = 0; i < Num; i++)
		tmp[i] = abs(Ducci[i] - Ducci[i + 1]);
	for(int i = 0; i < Num; i++)
		Ducci[i] = tmp[i];
	Ducci[Num] = Ducci[0];
}

int main()
{
	int Case;
	scanf("%d", &Case);
	while(Case--)
	{
		memset(Ducci, 0, sizeof(Ducci));
		scanf("%d", &Num);
		for(int i = 0; i < Num; i++)
			scanf("%d", &Ducci[i]);
		Ducci[Num] = Ducci[0];

		bool Ans = false;
		for(int i = 0; i < 1000; i++)
		{
			if(check())
			{
				Ans = true;
				break;
			}
			else
				next();
		}
		if(Ans)
			printf("ZERO\n");
		else
			printf("LOOP\n");
	}
	return 0;
}
