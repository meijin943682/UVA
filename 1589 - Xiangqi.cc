#include <cstdio>
#include <cstring>
using namespace std;

char board[12][12];
int dr[4] = { 1, -1, 0, 0 }, dc[4] = { 0, 0, 1, -1 };
int chr[4] = { 0, 0, 1, -1 }, chc[4] = { 1, -1, 0, 0 };
int hr[8] = { -2, -1, -2, -1, 1, 2, 1, 2 };
int hc[8] = { -1, -2, 1, 2, -2, -1, 2, 1 };
int hlr[8] = { -1, -1, -1, -1, 1, 1, 1, 1 };
int hlc[8] = { -1, -1, 1, 1, -1, -1, 1, 1 };
int check(int, int);

int main()
{
	int n, bgr, bgc, r, c, cnt;
	char s[5];
	while (scanf("%d%d%d", &n, &bgr, &bgc) == 3 && n && bgr && bgc)
	{
		cnt = 0;
		memset(board, 0, sizeof(board));
		for (int i = 0; i < n; i++){
			scanf("%s%d%d", s, &r, &c);
			board[r][c] = s[0];
		}

		for (int i = 0; i < 4; i++)
			cnt += check(bgr + dr[i], bgc + dc[i]);
		if (cnt >= 4) printf("YES\n");
		else  printf("NO\n");
	}
}

int check(int r, int c)
{
	if (r < 1 || r > 3 || c < 4 || c > 6) return 1;


	for (int i = 0; i < 4; i++)
	{
		int cnt = 0;
		int nr = r + chr[i], nc = c + chc[i];
		for (; 0 < nr&&nr <= 10 && 0 < nc&&nc <= 9; nr += chr[i], nc += chc[i]){
			if (board[nr][nc]){
				if ((board[nr][nc] == 'R' || board[nr][nc] == 'G')&&cnt==0) return 1;
				else  if (board[nr][nc] == 'C'&&cnt==1)  return 1;
				cnt++;
			}
		}
	}

	for (int i = 0; i < 8; i++)
	{
		int nr = r + hr[i], nc = c + hc[i];
		if (0 < nr&&nr <= 10 && 0 < nc&&nc <= 9 &&
				board[nr][nc] == 'H'&&!board[r + hlr[i]][c + hlc[i]])
			return 1;
	}
	return 0;
}
