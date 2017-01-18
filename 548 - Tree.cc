#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

void pushNumber(vector<int> &list, string &line)
{
    stringstream sin(line);
    int n;
    while(sin >> n)
        list.push_back(n);
}

class Node
{
	public:
	    int value;
    	int sum;
    	Node* left;
    	Node* right;

    	Node() : value(0), sum(0), left(NULL), right(NULL){}
    	Node(int num) : value(num), left(NULL), right(NULL){}
};

Node* treeBuilding(vector<int> :: iterator begin, vector<int> :: iterator end, vector<int>& post)
{
    if(post.empty())
        return NULL;
    vector<int> :: iterator it = find(begin, end, post.back());
    if(it == end)
        return NULL;

    int val = post.back();
    post.pop_back();

    Node* now = new Node(val);
    now -> right = treeBuilding(it + 1, end, post);
	now -> left = treeBuilding(begin, it, post);
    return now;
}

int best, best_sum;

void DFS(Node* now, int sum)
{
	sum += now -> value;
    if(now -> left == NULL && now -> right == NULL)
	{
		if(sum < best_sum || (sum == best_sum && now -> value < best))
		{
			best = now -> value;
			best_sum = sum;
		}
	}
	if(now -> left)
    	DFS(now -> left, sum);
    if(now -> right)
		DFS(now -> right, sum);
}

int main()
{
	string line1, line2;
    while(getline(cin, line1) && getline(cin, line2))
    {
		best = 100000, best_sum = 100000;
        vector<int> inOrder, postOrder;
        pushNumber(inOrder, line1);
        pushNumber(postOrder, line2);
        Node* root = treeBuilding(inOrder.begin(), inOrder.end(), postOrder);
        DFS(root, 0);
        cout << best << endl;
    }
	return 0;
}
