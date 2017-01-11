#include<map>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

map<string, vector<string> > graph;

void BFS(string start, string target)
{
	queue<string> q;
	q.push(start);
	map<string, int> visit;
	visit[start] = 1;

	while(!q.empty())
	{
		string top = q.front();
		q.pop();
		if(top == target)
			break;
		for(int i = 0; i < graph[top].size(); i++)
		{
			if(!visit[graph[top][i]])
				visit[graph[top][i]] = visit[top] + 1;
			q.push(graph[top][i]);
		}
	}

	int step = visit[target];
	vector<char> ans;
	ans.push_back(target[0]);
	string cur = target;
	while(step != 1)
	{
		for(int i = 0; i < graph[cur].size(); i++)
		{
			if(visit[graph[cur][i]] == step - 1)
			{
				ans.push_back(graph[cur][i][0]);
				step--;
				cur = graph[cur][i];
				break;
			}
		}
	}
	vector<char> :: iterator iter;
	for(iter = ans.end() - 1; iter != ans.begin(); iter--)
		cout << *iter;
	cout << ans[0] << endl;
}

int main()
{
	int C;
	cin >> C;
	while(C--)
	{
		graph.clear();
		int roadNum, quest;
		cin >> roadNum >> quest;
		for(int i = 0; i < roadNum; i++)
		{
			string placeA, placeB;
			cin >> placeA >> placeB;
			graph[placeA].push_back(placeB);
			graph[placeB].push_back(placeA);
		}

		for(int i = 0; i < quest; i++)
		{
			string start, target;
			cin >> start >> target;
			BFS(start, target);
		}
		if(C)
			cout << endl;
	}
	return 0;
}
