#include<stdio.h>
#include<string.h>

typedef long long int ll;

ll reverse (ll input)
{
	ll store = 0;
	while(input / 10 > 0)
	{
		store = store * 10 + input % 10;
		input = input / 10;
	}
	store = store * 10 + input;
	return store;
}

int main ()
{
	int N;
	scanf("%d", &N);
	while(N--)
	{
		ll P, R;
		int count = 0, i;
		scanf("%lld", &P);
		R = reverse (P);
		while(P != R)
		{
			P += R;
			R = reverse (P);
			count++;
		}
		printf("%d %lld\n", count, P);
	}

	return 0;
}
