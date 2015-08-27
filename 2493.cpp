#include <stdio.h>

int N;

int arr[500001];
int idx[500001];
int s_idx;

int repeat = 0;

int main(void)
{
	int i, j;

	scanf("%d", &N);	
	

	for(i=0; i<N; i++)	{
		scanf("%d", &arr[i]);	
	}

	printf("0 ");

	for(i=1; i<N; i++)	{
		s_idx = i-1;
		repeat = 0;

		while(1)
		{
			if(arr[s_idx] >= arr[i])	{
				//printf("%d : %d \n", i + 1, s_idx + 1);	//print it
				printf("%d ", s_idx + 1);
				idx[i] = s_idx;
				
				break;
	
			else	{
				s_idx = idx[s_idx];

				if(repeat == 1)	{
					printf("0 ");
					break;
				}
				else if(s_idx == 0)	{
					repeat = 1;
				}

				//printf("!!%d\n", s_idx);
			}

			if(s_idx < 0)	{
				//printf("%d : 0 \n", i+1);
				printf("0 ");
				break;
			}	//break init

			//printf("!%d \n", s_idx);
		}	//while
	}

	return 0;
}

/*
20
1 2 3 4 5 6 7 8 9 10
3030 4040 5050 5555 4 44949 1 2 5453 5554
*/