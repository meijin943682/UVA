#include<cstdio>
using namespace std;

int main()
{
	int k;
	while(~scanf("%d", &k))
	{
		int ans[1000][2], now = 0;
		for(int y = k + 1; y <= 2 * k; y++)
		{
			if(y * k % (y - k) == 0)
				ans[now][0] = y * k / (y - k), ans[now++][1] = y;
		}
		printf("%d\n", now);
		for(int i = 0; i < now; i++)
			printf("1/%d = 1/%d + 1/%d\n", k, ans[i][0], ans[i][1]);
	}
	return 0;
}
