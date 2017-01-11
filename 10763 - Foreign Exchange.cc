#include<utility>
#include<map>
#include<iostream>
using namespace std;

map<pair<int, int>, int> mp;

bool ok()
{
	map<pair<int, int>, int> :: iterator iter;
	for(iter = mp.begin(); iter != mp.end(); iter++)
		if(iter -> second)
			return false;
	return true;
}

int main()
{
	int n;
	while(cin >> n && n)
	{
		mp.clear();
		while(n--)
		{
			int a, b;
			cin >> a >> b;
			a < b ? ++mp[make_pair(a,b)] : --mp[make_pair(b,a)];
		}
		cout << (ok() ? "YES" : "NO") << endl;
	}
	return 0;
}
