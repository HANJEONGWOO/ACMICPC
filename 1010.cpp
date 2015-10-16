#include <stdio.h>

int TC;

int arr[40][40];

int W, E;

int main(void)
{
	int i, j;

	scanf("%d", &TC);	//input TC

	while(TC--)
	{
		scanf("%d %d", &W, &E);	//input

		for(i=1; i<=30; i++)
			arr[1][i] = i;	//input

		for(i=2; i<=30; i++)	{
			for(j=i; j<=30; j++)	{
				arr[i][j] = arr[i-1][j-1] + arr[i][j-1];
			}
		}

		printf("%d\n", arr[W][E]);
	}


	return 0;
}
