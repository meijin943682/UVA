#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int p, a, b, c, d, n;
inline double count (int x)
{
	return p * (sin(a * x + b) + cos(c * x + d) + 2);
}

int main ()
{
	while(~scanf("%d%d%d%d%d%d", &p, &a, &b, &c, &d, &n))
	{
		double Max = count(1), ans = 0;
		for(int i = 2; i <= n; i++)
		{
			double data = count(i);
			if(data > Max)
				Max = data;
			else
				ans = max(Max - data, ans);
		}
		if(ans == 0)
			printf("0.00\n");
		else
			printf("%.10f\n", ans);
	}
	return 0;
}
