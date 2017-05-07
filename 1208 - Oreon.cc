#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

class path
{
	public:
		int x, y, l;
		path(int x, int y, int l) : x(x), y(y), l(l){};
		bool operator <(const path& b)
		{
			return l < b.l || ( l == b.l  && (x < b.x || (x == b.x && y < b.y)));
		}
};

void check(vector<path>& map, int N)
{
	int forest[30], set_sum = 1;
	memset(forest, 0, sizeof(forest));
	sort(map.begin(), map.end());

	while(!map.empty())
	{
		path take = map.front();
		map.erase(map.begin());
		int uset = forest[take.x], vset = forest[take.y];
		
		int max = (uset < vset)? vset : uset;
		if(uset == 0 && vset == 0)
			forest[take.x] = set_sum, forest[take.y] = set_sum++;
		else if(uset == 0 || vset == 0)
			forest[take.x] = max, forest[take.y] = max;
		else if(uset != vset)
		{
			int min = (uset < vset)? uset : vset;
			for(int i = 0; i < N; i++)
				if(forest[i] == max)
					forest[i] = min;
		}
		else
			continue;

		cout << (char)(take.x + 'A') << "-" << (char)(take.y + 'A') << " " << take.l << endl;
	}
}
int main()
{
	int Case, N, num;
	cin >> Case;
	vector<path> map;
	for(int i = 1; i <= Case; i++)
	{
		cout << "Case " << i << ":" << endl;
		cin >> N;
		for(int j = 0; j < N; j++)
		{
			for(int k = 0; k < N; k++)
			{
				char cha;
				cin >> num;
				if(k != N - 1) cin >> cha;
				if(num != 0 && k > j)
				{
					path node(j, k, num);
					map.push_back(node);
				}
			}
		}
		check(map, N);
	}
	return 0;
}
