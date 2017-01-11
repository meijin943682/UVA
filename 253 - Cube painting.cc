#include<cstdio>
using namespace std;

const int table[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
bool check(char cube[][3][2], int now)
{
	for(int i = 0; i < 3; i++)
	{
		if((cube[0][i][0] != cube[1][table[now][i]][0] || cube[0][i][1] != cube[1][table[now][i]][1]) && (cube[0][i][1] != cube[1][table[now][i]][0] || cube[0][i][0] != cube[1][table[now][i]][1]))
			return false;
	}
	return true;
}

int main ()
{
	char input[12];
	while(~scanf("%s", &input))
	{
		char cube[2][3][2];
		for(int i = 0; i < 2; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				cube[i][j][0] = input[j + i * 6];
				cube[i][j][1] = input[5 - j + i * 6];
			}
		}
		bool ch = false;
		for(int i = 0; i < 6; i++)
		{
			if(check(cube, i))
				ch = true;
		}
		if(ch)
			puts("TRUE");
		else
			puts("FALSE");
	}

	return 0;
}
