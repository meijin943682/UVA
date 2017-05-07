#include<cstdio>
#include<vector>
using namespace std;

void DFS(int now, int visit[], vector<int> toNode[], vector<int>& ans)
{
	if(visit[now] == 1)	return;
	visit[now] = 1;
	for(vector<int> :: iterator iter = toNode[now].begin(); iter != toNode[now].end(); iter++)
	{
		if(visit[*iter] != 2)
			DFS(*iter, visit, toNode, ans);
	}
	visit[now] = 2;
	ans.push_back(now);
}

int main()
{
	int N, M;
	while(scanf("%d%d", &N, &M) && N && M)
	{

		vector<int> toNode[111]; 
		vector<int> ans;
		int visit[111] = {0};
		bool connect[111] = {false};

		while(M--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			toNode[a].push_back(b);
			connect[b] = true;
		}
		for(int i = 1; i <= N; i++)
		{
			if(!connect[i])
				DFS(i, visit, toNode, ans);
		}
		for(vector<int> :: iterator iter = ans.end() - 1; iter != ans.begin(); iter--)
			printf("%d ", *iter);
		printf("%d\n", *ans.begin());
	}	
	return 0;
}
