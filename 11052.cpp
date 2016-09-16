#include <stdio.h>

int N;
int bread[1100];
int DT[1100];

void bottom_up(int N)
{
	DT[1] = bread[1]; //input

	for (int i = 2; i <= N; i++)
	{
		DT[i] = bread[i];
		for (int j = 1; j < i; j++)
		{
			if (DT[i] < DT[i - j] + bread[j])
				DT[i] = DT[i - j] + bread[j];
		} //for j
	} //for i
}

int top_down(int N)
{
	if (N <= 0)
		return 0;
	else if (N == 1) {
		DT[1] = bread[1];
		return DT[1];
	}
	else
	{
		if (DT[N] != 0)
			return DT[N];
		else
		{
			DT[N] = bread[N];
			for (int j = 1; j < N; j++)
			{
				int attempt = top_down(N - j) + bread[j];
				if (DT[N] < attempt)
					DT[N] = attempt;
			}
			return DT[N]; //return it!!!
		}
	}
}

int main(void)
{
	scanf("%d", &N); //input N

	for (int i = 1; i <= N; i++)
		scanf("%d", &bread[i]); //input

								//bottom_up(N);
								//printf("%d\n", DT[N]);

	printf("%d\n", top_down(N));

	return 0;
}
