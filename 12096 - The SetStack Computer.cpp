#include<stdio.h>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
#include<string.h> 

using namespace std;

const int MAXN = 2010;

int cnt;
set<int> s1,s2;
map<set<int> ,int> mp;
stack <set<int> > stk;

void Pop()
{
	s1=stk.top();
	stk.pop();
	s2=stk.top();
	stk.pop();
}

void Push()
{
	set<int> s;
	stk.push(s);
	printf("0\n");
}
void Dup ()
{
	set<int> s;
	s=stk.top();
	stk.push(s);
	printf("%d\n",s.size());
}
void Union()
{
	Pop();
	set<int>::iterator iter;
	for(iter=s1.begin();iter != s1.end();iter++)
		s2.insert(*iter);
	stk.push(s2);
	printf("%d\n",s2.size());
}
void Intersect()
{
	Pop();
	set<int> s3;
	set<int>::iterator iter;
	for(iter=s1.begin();iter != s1.end();iter++)
	{
		if(s2.find(*iter) != s2.end())
			s3.insert(*iter);
	}
	stk.push(s3);
	printf("%d\n",s3.size());
}

void Add ()
{
	Pop();
	if(s1.empty())
		s2.insert(0);
	else
	{
		if(!mp[s1])
			mp[s1]= cnt++;
		s2.insert(mp[s1]);
	}
	stk.push(s2);
	printf("%d\n",s2.size());
	
}
int main ()
{
	int round,num;
	scanf("%d",&round);
	while(round--)
	{
		
		while(!stk.empty())
			stk.pop();
		mp.clear();
		
		cnt =MAXN;
		scanf("%d",&num);
		while(num--)
		{
			char cmd[20];
			scanf("%s",cmd);
			if(cmd[0]=='P')
				Push();
			else if(cmd[0]=='D')
				Dup();
			else if(cmd[0]=='U')
				Union();
			else if(cmd[0]=='I')
				Intersect();
			else
				Add();	
		}
		puts("***");
	}
	return 0;
}
 
