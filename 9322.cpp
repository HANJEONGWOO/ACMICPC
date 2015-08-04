#include <stdio.h>
#include <string.h>

char str1[1100][15];
char str2[1100][15];

int idx_str[1100];

char sequ[1100][15];
char plain[1100][15];

int N;
int num;
int cnt;	//count current;

int main(void)
{
	int i, j;
	
	scanf("%d", &N);	//input N

	while(N--)
	{
		//init 
		cnt = 0;

		scanf("%d", &num);	//input this

		for(i=0; i<num; i++)	{
			scanf("%s", &str1[i]);
		}
		for(i=0; i<num; i++)	{
			scanf("%s", &str2[i]);	//input
		}

		while(num > cnt)	//cnt가 넘과 같아지면 탈출하게해
		{
			for(i=0; i<num; i++)	{
				if(strcmp(str1[cnt], str2[i]) == 0)	{
					idx_str[i] = cnt;	//write cnt_idx;;
					cnt++;
					break;
				}	//if
			}	//for i
			
		}	//while

		for(i=0; i<num; i++)	{
			scanf("%s", &sequ[i]); //input sequ code
			strcpy(plain[ idx_str[i]], sequ[i]); //string copy it
		}
		for(i=0; i<num; i++)	{
			printf("%s ", plain[i]);
		}	//result print it

	}	//while(N--)

	return 0;
}
/*
2
4
A B C D
D A B C
C B A P
3
SECURITY THROUGH OBSCURITY
OBSCURITY THROUGH SECURITY
TOMORROW ATTACK WE

*/


