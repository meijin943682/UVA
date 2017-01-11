#include<cstdio>
#include<algorithm>
using namespace std;

typedef struct square
{
	int len, wid;
}Square;

bool cmp(Square a, Square b)
{
	return a.len < b.len || (a.len == b.len && a.wid < b.wid);
}

int main ()
{
	Square box[6];

	while(scanf("%d %d", &box[0].len, &box[0].wid) == 2)
	{
		int now = 0, ok = 1;		
		if(box[0].len < box[0].wid)
			swap(box[0].len, box[0].wid);

		for(now = 1; now < 6; now++)
		{
			scanf("%d %d", &box[now].len, &box[now].wid);
			if(box[now].len < box[now].wid)
				swap(box[now].len, box[now].wid);
		}

		sort(box, box + 6, cmp);
		for(int i = 0; i < 6; i += 2)
			if(box[i].len != box[i + 1].len || box[i].wid != box[i + 1].wid)
				ok = 0;

		if(box[0].wid != box[2].wid || box[2].len != box[4].len || box[0].len != box[4].wid)
			ok = 0;

		puts(ok ? "POSSIBLE" : "IMPOSSIBLE");
	}
	return 0;
}
