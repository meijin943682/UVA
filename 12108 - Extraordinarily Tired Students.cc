#include<cstdio>
#define LIMIT 1000000

int Count;

void next(int StudNum, int StudData[][3])
{
	for(int i = 0; i < StudNum; i++)
	{
		StudData[i][2] %= StudData[i][0] + StudData[i][1];
		if(StudData[i][2] == StudData[i][0] && Count >= StudNum - Count)
			StudData[i][2] = 0;
		StudData[i][2]++;
	}
}

bool all_wake(int StudNum, int StudData[][3])
{
	Count = 0;
	for(int i = 0; i < StudNum; i++)
		if(StudData[i][2] <= StudData[i][0])
			Count++;
	if(Count == StudNum)
		return true;
	else
		return false;
}

int main()
{
	int StudNum, Case = 0;
	while(~scanf("%d", &StudNum) && StudNum != 0)
	{
		Case++;
		int StudData[10][3], MinRound = 1;
		for(int i = 0; i < StudNum; i++)
			scanf("%d%d%d", &StudData[i][0], &StudData[i][1], &StudData[i][2]);
		
		int i;
		for(i = 1; i < LIMIT; i++)
		{
			if(all_wake(StudNum, StudData))
				break;
			next(StudNum, StudData);
		}

		if(i < LIMIT)
			printf("Case %d: %d\n", Case, i);
		else
			printf("Case %d: -1\n", Case);

	}
	return 0;
}
