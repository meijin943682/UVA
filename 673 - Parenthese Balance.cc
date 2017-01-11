#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

int main()
{
	int n;
	cin >> n;
	getchar();
	while(n--)
	{
		stack<char> sc;
		while(!sc.empty())
			sc.pop();
		char input[222];
		fgets(input, sizeof(input), stdin);
		bool check = true;
		for(int i = 0; i < strlen(input); i++)
		{
			if(input[i] == '[' || input[i] == '(')
				sc.push(input[i]);
			else if(input[i] == ']')
			{
				if(sc.empty() || sc.top() != '[')
				{
					check = false;
					break;
				}
				sc.pop();
			}
			else if(input[i] == ')')
			{
				if(sc.empty() || sc.top() != '(')
				{
					check = false;
					break;
				}
				sc.pop();
			}
		}
		if(!sc.empty())
			check = false;
		cout << (check ? "Yes" : "No") << endl;
	}
	return 0;
}
