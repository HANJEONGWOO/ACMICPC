#include <stdio.h>

int K, N;	//가지고 있는수, 필요한 수

int lan[11000];	//랜선 저장
int max, min;

int result;

int bsearch(int min, int max);

int main(void)
{
	int i, j;

	scanf("%d %d", &K, &N);	//input this
	
	max = lan[0];
	min = lan[0];
	for(i=0; i<K; i++)	{
		scanf("%d", &lan[i]);

		if(max < lan[i])	{
			max = lan[i];
		}
		if(min > lan[i])	{
			min = lan[i];
		}
	}	//for i

	bsearch(0, max);

	printf("%d\n", result);

	return 0;
}

int bsearch(int min, int max)
{	//init min - 0 , max - max value, value is N
	int i, j;
	int mid = (min + max) / 2;
	int lan_value=0;

	//printf("%d\n", mid);
	if(min <= max)
	{

	for(i=0; i<K; i++)	{
		lan_value += lan[i] / mid;
	}

	if(lan_value >= N)	{
		//printf("!%d\n", mid);
		result = mid;
		return bsearch(mid+1, max);
	}
	else if(lan_value < N)	{
		return bsearch(min, mid-1);	
	}

	}
}
/*
4 11
802
743
457
539
*/