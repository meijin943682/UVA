#include<queue>
#include<cstdio>
#include<cstring>
#include<utility>
#define MAXN 22
using namespace std;

class point
{
	public:
		point(int dx, int dy, int ds,int db) : x(dx), y(dy), step(ds), barrier(db){};
		int x, y, step, barrier;
};

queue<point> q;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int bx, by, board[MAXN][MAXN], k;

int bfs()
{
	int dist[MAXN][MAXN][MAXN];
	memset(dist, 0, sizeof(dist));
	while(!q.empty())
	{
		point now = q.front();
		q.pop();
		if(now.x == bx - 1 && now.y == by - 1)
			return now.step;

		for(int i = 0; i < 4; i++)
		{
			int x = now.x + dir[i][0], y = now.y + dir[i][1], step = now.step + 1, barrier = now.barrier;
			if(x < 0 || x >= bx || y < 0 || y >= by)
				continue;
			if(board[x][y] == 1)
				barrier += 1;
			else
				barrier = 0;

			if(barrier > k)
				continue;
			if(dist[x][y][barrier])
				continue;

			point new_p(x, y, step, barrier);
			q.push(new_p);
			dist[x][y][barrier] = 1;
		}
	}
	return -1;
}

int main()
{
	int round;
	scanf("%d", &round);
	while(round--)
	{
		scanf("%d%d%d", &bx, &by, &k);
		memset(board, 0, sizeof(board));
		for(int i = 0; i < bx; i++)
			for(int j = 0; j < by; j++)
				scanf("%d", &board[i][j]);

		point first(0, 0, 0, 0);
		q.push(first);
		int ans = bfs();
		printf("%d\n", ans);
		while(!q.empty())
			q.pop();
	}
	return 0;
}
