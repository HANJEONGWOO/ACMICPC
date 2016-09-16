#include <stdio.h>

int N;

int DT[1100][11];

int result;

void bottom_up(int N)
{
	for (int i = 0; i < 10; i++)
	{
		DT[1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				DT[i][j] = DT[i - 1][j] % 10007;
			else
				DT[i][j] = (DT[i - 1][j] + DT[i][j - 1]) % 10007;
		}
	}
}

int main(void)
{
	scanf("%d", &N);

	bottom_up(N);

	for (int i = 0; i < 10; i++)
	{
		result += DT[N][i] % 10007;
	}
	result = result % 10007;

	printf("%d\n", result);

	return 0;
}