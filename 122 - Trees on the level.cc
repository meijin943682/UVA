#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

typedef struct _Node
{
	bool have;
	struct _Node* left;
	struct _Node* right;
	int num;

	_Node() : have(false), left(NULL), right(NULL){}
}Node;

Node* root;
bool fail;
vector<int> ans;

bool bfs()
{
	queue<Node*> qNode;
	qNode.push(root);
	ans.clear();
	while(!qNode.empty())
	{
		Node* now = qNode.front();
		qNode.pop();

		if(!(now -> have))
			return false;

		ans.push_back(now -> num);
		if(now -> left != NULL)
			qNode.push(now -> left);
		if(now -> right != NULL)
			qNode.push(now -> right);
	}
	return true;
}

void addNode(int num, char* str)
{
	Node* now = root;
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] == 'L')
		{
			if(now -> left == NULL)
				now -> left = new Node();
			now = now -> left;
		}
		else if(str[i] == 'R')
		{
			if(now -> right == NULL)
				now -> right = new Node();
			now = now -> right;
		}
	}
	if(now -> have)
		fail = true;

	now -> num = num;
	now -> have = true;
}

void remove(Node* now)
{
	if(now == NULL)
		return;
	remove(now -> left);
	remove(now -> right);
	delete now;
}
int main()
{
	char input[111];
	fail = false;
	root = new Node();
	while(scanf("%s", input) != EOF)
	{
		if(strcmp(input, "()") == 0)
		{
			if(!bfs())
				fail = true;
			if(fail)
				printf("not complete\n");
			else
			{
				for(int i = 0; i < ans.size() - 1; i++)
					printf("%d ", ans[i]);
				printf("%d\n", ans[ans.size() - 1]);
			}

			remove(root);
			fail = false;
			root = new Node();
			continue;
		}

		int num;
		sscanf(&input[1], "%d", &num);
		addNode(num, strchr(input, ',') + 1);
	}
	return 0;
}
