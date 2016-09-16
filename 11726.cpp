#include <stdio.h>

int N;

int DT[1100];

int main(void)
{
	scanf("%d", &N); //input N

	DT[1] = 1;
	DT[2] = 2;

	for (int i = 3; i <= 1000; i++)
	{
		DT[i] = (DT[i - 1] + DT[i - 2]) % 10007;
	}

	printf("%d\n", DT[N]);

	return 0;
}