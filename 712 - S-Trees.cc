#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, Case = 1, m;
	while(cin >> n && n)
	{
		if(Case != 1)
			cout << endl;
		cout << "S-Tree #" << Case++ << ":" << endl;

		vector<int> order;
		for(int i = 0; i < n; i++)
		{
			char or_input[11];
			cin >> or_input;
			order.push_back(or_input[1] - '0');
		}

		char tree[1 << 7];
		cin >> tree >> m;

		while(m--)
		{
			char VVA[11];
			cin >> VVA;
			
			int node_num = 0;
			for(int i = 0; i < n; i++)
			{
				int direction = VVA[order[i] - 1] - '0'; 
				node_num = node_num * 2 + direction;
			}
			cout << tree[node_num];
		}
		cout << endl;
	}
	return 0;
}
