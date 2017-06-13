#include<cstdio>
#define MAXN 17
using namespace std;

int A[MAXN], num, round = 1;
bool vis[MAXN], isPrime[2 * MAXN];

void prime()
{
	for(int i = 2; i < 2 * MAXN; i++){
		bool check = true;
		for(int j = 2; j < i; j++)
			if(i % j == 0)
				check = false;
		isPrime[i] = check;
	}
}

void dfs(int cur)
{
	if(cur == num && isPrime[A[0] + A[num -1]]){
		for(int i = 0; i < num - 1; i++)
			printf("%d ", A[i]);
		printf("%d\n", A[num - 1]);
	}

	else{
		for(int i = 2; i <= num; i++){
			if(!vis[i] && isPrime[i + A[cur - 1]]){
				A[cur] = i;
				vis[i] = 1;
				dfs(cur + 1);
				vis[i] = 0;
			}
		}
	}
}


int main()
{
	prime();
	A[0] = 1;
	while(~scanf("%d", &num)){
		if(round != 1) printf("\n");
		printf("Case %d:\n", round++);
		dfs(1);
	}
	return 0;
}
