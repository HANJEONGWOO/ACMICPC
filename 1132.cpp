#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TEST 0

unsigned long long int N;
unsigned long long int alpa[10];	//a is 0 j is 9 save ga jung chi

unsigned long long int transform[10];	//a idx is 0 and j idx is 9 -> this transform in 0 ~ 9 value

unsigned long long int length[55];

char str[55][20];

unsigned long long int result;

int main(void)
{
	int i, j;

	scanf("%lld", &N);	//input this

	for(i=0; i<10; i++)	{
		alpa[i] += i;	//separate ga jung chi
	}

	for(i=0; i<N; i++)	{
		scanf("%s", &str[i]);
		length[i] = strlen(str[i]);
	}	//input


	for(i=0; i<N; i++)	{
		unsigned long long int gop = 10;	//init is 10 ---> because 1 is separate gajungchi

		for(j=length[i]-1; j>=0; j--)	{
			alpa[str[i][j] - 'A'] += gop;	//plus gop

			gop *= 10;	//gop is multiply 10
		}
	}


	
	for(i=0; i<10; i++)	{
		unsigned long long int bigger = 0;
		for(j=0; j<10; j++)	{
			if(i != j)	{
				if(alpa[i] < alpa[j])	{
					bigger++;
				}
			}
		}	//for j

		transform[i] = 9 - bigger;	//save transform
	}	//for i

	for(i=0; i<N; i++)	{
		unsigned long long int gop = 1;

		for(j=length[i]-1; j>=0; j--)	{
			
			result += (transform[ str[i][j] - 'A'] * gop);
			gop *= 10;
		}	//for j
		if(TEST)	{
			printf("%lld\n", result);
		}	
	}	//for i

	

	printf("%lld\n", result);
	
	return 0;
}

/*
2
ABCDEFGHIJ
JIHGFEDCBA

*/