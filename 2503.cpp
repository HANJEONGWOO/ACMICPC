#include <stdio.h>
#include <string.h>

int N;
int strike;
int ball;

char doit[4];
int t_count;

int s_count;
int b_count;

char arr[1000][4];
int chk_arr[1000];

int result;

//int temp_count;

void func(int strike, int ball, int end);

int main(void)
{
	int i, j, k, l=0;

	for(i='1'; i<= '9'; i++)	{
		for(j='1'; j<='9'; j++)	{
			for(k='1'; k<='9'; k++)	{
				if(i != j && j != k && k != i)	{
					arr[l][0] = i;
					arr[l][1] = j;
					arr[l][2] = k;
					arr[l][3] = NULL;
					l++;
				}	//if
			}	//k
		}	//j
	}	//i
	
	/*
	for(i=0; i<l; i++)	{
		printf("%s ", arr[i]);
	}
	printf("%d\n", l);
	*/

	scanf("%d", &N);	//input N

	for(i=0; i<N; i++)	{
		scanf("%s %d %d", &doit, &strike, &ball);

		s_count = 0;
		b_count = 0;

		if(strike == 3 && ball == 0)	{
			func(3, 0, l);
		}
		else if(strike == 0 && ball == 3)	{
			func(0, 3, l);
		}
		else if(strike==0 && ball==0)	{
			func(0, 0, l);
		}
		else if(strike == 1 && ball == 0)	{
			func(1, 0, l);
		}
		else if(strike == 2 && ball == 0)	{
			func(2, 0, l);
		}
		else if(strike == 0 && ball == 1)	{
			func(0, 1, l);
		}	//if
		else if(strike == 0 && ball == 2)	{
			func(0, 2, l);
		}
		else if(strike == 1 && ball == 1)	{
			func(1, 1, l);
		}
		else if(strike == 1 && ball == 2)	{
			func(1, 2, l);
		}
		else if(strike == 2 && ball == 1)	{
			func(2, 1, l);
		}

		//printf("t : %d\n", temp_count);
		//temp_count = 0;

	}	//for i

	for(i=0; i<l; i++)	{
		if(chk_arr[i] == 0)	{
			result++;
		}
	}
	printf("%d\n", result);

	return 0;
}

void func(int strike, int ball, int end)	{
	int s_count = 0;
	int b_count = 0;

	int i, j;

	for(i=0; i<end; i++)	{
		s_count = 0;
		b_count = 0;

		for(j=0; j<3; j++)		{
			if( ( (doit[j]==arr[i][0]) && (j == 0) ) || ( (doit[j]==arr[i][1]) && (j == 1) ) || ( (doit[j]==arr[i][2]) && (j == 2) ) )	{
				s_count++;
			}
			
			if( ( (doit[j]==arr[i][0]) && (j != 0) ) || ( (doit[j]==arr[i][1]) && (j != 1) ) || ( (doit[j]==arr[i][2]) && (j != 2) ) )	{
				b_count++;
			}
		}	//for j

		if( (s_count != strike) || (b_count != ball) )	{
			chk_arr[i] = 1;
			//temp_count++;
		}

	}	//for i

}	//end