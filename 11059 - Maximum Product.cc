#include<cstdio>
#define MAXN 18
using namespace std;

int main()
{
	int n, round = 1;
	while(~scanf("%d", &n)){
		long long int input[MAXN], max = 0, local;
		for(int i = 0; i < n; i++)
			scanf("%lld", &input[i]);

		for(int i = 0; i < n; i++){
			local = 1;
			for(int j = i; j < n; j++){
				local *= input[j];
				if(local > max)
					max = local;
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", round++, max);
	}
	return 0;
}
