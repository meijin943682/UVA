#include<cstdio>
#include<cstring>

char map[111][111];
int direction[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void dfs(int x, int y)
{
	map[x][y] = '*';
	for(int i = 0; i < 8; i++)
		if(map[x + direction[i][0]][y + direction[i][1]] == '@')
			dfs(x + direction[i][0], y + direction[i][1]);
}

int main()
{
	int m, n;
	while(scanf("%d %d", &m, &n) && (m != 0 && n != 0))	
	{
		getchar();
		memset(map, '\0', sizeof(map));
		for(int i = 0; i < m; i++)
			scanf("%s", map[i]);

		int ans = 0;
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(map[i][j] == '@')
				{
					dfs(i, j);
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
