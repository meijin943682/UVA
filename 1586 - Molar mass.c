#include<stdio.h>
#include<string.h>
#include<ctype.h>

const float CHON[4] = {12.01, 1.008, 16.00, 14.01};

int main ()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		char molor[100];
		scanf("%s", molor);
		int len = strlen(molor), i, amount = 1;
		float now_mass = 0, ans = 0.0;

		for(i = 0; i < len; i++)
		{
			if(isdigit(molor[i]) && isdigit(molor[i - 1]))
				amount = amount * 10 + (int)(molor[i] - '0');
			else if(isdigit(molor[i]))
				amount = (amount - 1) * 10 + (int)(molor[i] - '0');
			else
			{
				ans += now_mass * amount;
				switch(molor[i])
				{
					case 'C':
						now_mass = CHON[0];
						break;
					case 'H':
						now_mass = CHON[1];
						break;
					case 'O':
						now_mass = CHON[2];
						break;
					case 'N':
						now_mass = CHON[3];
						break;
				}
				amount = 1;
			}
		}
		ans += now_mass * amount;
		printf("%.3f\n", ans);
	}
	return 0;
}
