#include <stdio.h>

int N;
long long int DT[110][2];

long long int result;

void bottom_up(int N)
{
	DT[1][1] = 1;

	for (int i = 2; i <= N; i++)
	{
		DT[i][0] = DT[i - 1][0] + DT[i - 1][1];
		DT[i][1] = DT[i - 1][0];
	}
}


int main(void)
{
	scanf("%d", &N);

	bottom_up(N);

	result = DT[N][0] + DT[N][1];

	printf("%lld\n", result);

	return 0;
}