#include<iostream>
using namespace std;

bool solve(int& W)
{
	int W1, D1, W2, D2;
	cin >> W1 >> D1 >> W2 >> D2;
	bool b1 = true, b2 = true;
	if(!W1)
		b1 = solve(W1);
	if(!W2)
		b2 = solve(W2);

	W = W1 + W2;
	return b1 && b2 && (W1 * D1 == W2 * D2);
}

int main()
{
	int Case;
	cin >> Case;
	for(int i = 0; i < Case; i++)
	{
		if(i != 0)
			cout << endl;
		int W = 0;
		bool ans = solve(W);
		if(ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;	
	}
	return 0;
}
