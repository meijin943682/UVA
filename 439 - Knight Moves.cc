#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

class loc
{
	public:
		loc(int nx, int ny, int r) : x(nx), y(ny), round(r){};
		int x, y, round;
};

queue<loc> map;

int step[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

bool checkboard(int x, int y)
{
	return (0 <= x && x < 8) && (0 <= y && y < 8);
}

int solve(int sx, int sy, int dx, int dy)
{
	while(!map.empty())
		map.pop();

	bool board[8][8];
	memset(board, false, sizeof(board));
	loc first(sx, sy, 0);
	map.push(first);
	while(!map.empty())
	{
		loc front = map.front();
		map.pop();
		if(front.x == dx && front.y == dy)
			return front.round;
		board[front.x][front.y] = true;

		for(int i = 0; i < 8; i++)
		{
			loc tmp(front.x + step[i][0], front.y + step[i][1], front.round + 1);
			if(checkboard(tmp.x, tmp.y) && !board[tmp.x][tmp.y])
				map.push(tmp);
		}	
	}
	
	return -1;
}

int main()
{
	int sx, sy, dx, dy;
	char from[5], to[5];
	while(cin >> from >> to)
	{
		sx = from[1] - '1', dx = to[1] - '1';
		sy = from[0] - 'a', dy = to[0] - 'a';

		int ans = solve(sx, sy, dx, dy);
		cout << "To get from " << from << " to " << to << " takes " << ans << " knight moves." << endl;
	}

	return 0;
}
