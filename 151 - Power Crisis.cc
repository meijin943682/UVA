#include<cstdio>
#include<cstring>

// this is josephus problem, this would delete a point according m and rearrange it.
using namespace std;

int main()
{
	int num, m, last;
	while(~scanf("%d", &num) && num != 0)
	{
		num--;
		for(m = 1; m < num; m++)
		{
			last = 1; // In the end, it must be 0
			for(int i = 1; i <= num; i++)
				last = (last + m) % i + 1; // last one in the i-th last round is rearranged at which point.
			if(last == 11)
				break;
		}
		printf("%d\n", m);
	}
	return 0;
}
