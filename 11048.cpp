#include <stdio.h>

int N, M;
int map[1100][1100];

int max(int a, int b, int c);

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i < N; i++)
	{
		map[i][0] += map[i - 1][0];
	}
	for (int j = 1; j < M; j++)
	{
		map[0][j] += map[0][j - 1];
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			map[i][j] += max(map[i - 1][j], map[i][j - 1], map[i - 1][j - 1]);
		}
	}

	printf("%d\n", map[N - 1][M - 1]);

	return 0;
}

int max(int a, int b, int c)
{
	if (a > b) {
		if (a > c)
			return a;
		else
			return c;
	}
	else {
		if (b > c)
			return b;
		else
			return c;
	}
}