#include <stdio.h>

int K;	//round

int C;	//input

int saero, garo;

int s_board[1100][1100];	//score board
int main(void)
{
	int i, j;

	scanf("%d", &K);	//round
	scanf("%d", &C);	//input

	for(i=0; i<=K; i++)	{
		for(j=0; j<=K; j++)	{
			s_board[i][j] = 1;	//init
		}
	}

	for(i=0; i<=K; i++)	{	// ¿µÈñ
		for(j=0; j<=K; j++)	{	// µ¿È£
			
			if(j > i + (K-j) + 1 )	{
				s_board[i][j] = 0;
			}

			if(i > j + (K-i) + 2)	{
				s_board[i][j] = 0;
			}
		}
	}	//for i
	
	/*
	//TEST
	for(i=0; i<=K; i++)	{
		for(j=0; j<=K; j++)	{
			printf("%d ", s_board[i][j]);
		}
		printf("\n");
	}
	*/
	for(i=0; i<C; i++)	{
		scanf("%d %d", &saero, &garo);

		printf("%d\n", s_board[saero][garo]);
	}

	return 0;
}
/*
5
4
5 5
5 1
0 3
1 4
*/