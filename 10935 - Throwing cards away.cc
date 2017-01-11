#include<queue>
#include<iostream>
using namespace std;

int main()
{
	int num;
	while(cin >> num && num != 0)
	{
		queue<int> q;
		for(int i = 1; i <= num; i++)
			q.push(i);

		cout << "Discarded cards:";
		int count = 0;
		while(q.size() != 1)
		{
			if(count)
				cout << ",";
			count++;
			cout << " " << q.front(); 
			q.pop();
			q.push(q.front());
			q.pop();
		}
		cout << endl;
		cout << "Remaining card: " << q.front() << endl;
		q.pop();
	}
	return 0;
}
