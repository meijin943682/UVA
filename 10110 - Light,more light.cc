#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	long long int num;
	while(~scanf("%d", &num) && num != 0)
	{
		bool check = false;
		for(long long int i = sqrt(num); i * i <= num; i++)
			if(i * i == num)
				check = true;
		if(check)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
