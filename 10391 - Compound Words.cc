#include<set>
#include<iostream>
using namespace std;

int main()
{
	set<string> ss;

	string s;
	while(cin >> s)
		ss.insert(s);

	for(set<string> :: iterator iter = ss.begin(); iter != ss.end(); iter++)
	{
		string sub1, sub2;
		int len = (*iter).length();
		for(int j = 0; j < len - 1; j++)
		{
			sub1 = (*iter).substr(0, j + 1);
			sub2 = (*iter).substr(j + 1, len - j);
			if(ss.find(sub1) != ss.end() && ss.find(sub2) != ss.end())
			{
				cout << (*iter) << endl;
				break;
			}
		}
	}
	return 0;
}
