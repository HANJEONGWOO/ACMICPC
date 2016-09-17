#include <stdio.h>

int N;

typedef struct paper {
	int bigger;
	int shorter;
	int value;
} PAPER;

PAPER p[110];

int DT[1100]; //calc DT

int result;

void quick(PAPER *arr, int n);

int main(void)
{
	int first, second;

	scanf("%d", &N); //input N

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &first, &second); //input first, second;

		if (first > second)
		{
			p[i].bigger = first;
			p[i].shorter = second;
		}
		else
		{
			p[i].bigger = second;
			p[i].shorter = first;
		}

		p[i].value = p[i].bigger * 10000 + p[i].shorter; //calc p[i].value
	} //for i

	quick(p, N); //quick it
				 /*
				 for (int i = 0; i < N; i++) {
				 printf("! %d %d\n", p[i].bigger, p[i].shorter);
				 }
				 */

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (p[i].shorter <= p[j].shorter && DT[i] < DT[j] + 1) {
				DT[i] = DT[j] + 1;
			}
		}
		if (result < DT[i])
			result = DT[i];
	}
	result++;

	printf("%d\n", result);

	return 0;
}

void quick(PAPER *arr, int n)
{
	int i, j;
	PAPER temp;
	int mid;

	if (n > 1)
	{
		i = -1;
		j = n - 1;
		mid = arr[n - 1].value;

		while (1)
		{
			while (arr[++i].value > mid); //naerimcha
			while (arr[--j].value < mid);

			if (i >= j)
				break;

			//swap two value
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}

		//swap pivot value;
		temp = arr[i];
		arr[i] = arr[n - 1];
		arr[n - 1] = temp;

		//re-quick
		quick(arr, i);
		quick(arr + i + 1, n - i - 1);
	}

}