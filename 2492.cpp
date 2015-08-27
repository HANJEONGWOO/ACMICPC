#include <stdio.h>

int m_saero;
int m_garo;

int T;	//treasure
int K;	//

typedef struct treasure	{
	int saero;
	int garo;
} TREASURE;

TREASURE tr[110];

int count;
int t_garo;
int t_saero;
int te_garo;
int te_saero;


int result;
int r_garo;
int r_saero;

int main(void)
{
	int i, j, k;

	scanf("%d %d %d %d", &m_garo, &m_saero, &T, &K);	//input this

	for(i=0; i<T; i++)	{
		scanf("%d %d", &tr[i].garo, &tr[i].saero);	//input this
	}

	for(i=0; i<T; i++)	{

		
		t_garo = tr[i].garo;
		te_garo = tr[i].garo + K;
		if(te_garo > m_garo)	{
			t_garo -= (te_garo - m_garo);
			te_garo = m_garo;
		}

		for(k=0; k<T; k++)	{

		t_saero = tr[k].saero;
		te_saero = tr[k].saero + K;
		if(te_saero > m_saero)	{
			t_saero -= (te_saero - m_saero);
			te_saero = m_saero;
		}
		
		count = 0;
		for(j=0; j<T; j++)	{
			if( (tr[j].garo >= t_garo && tr[j].garo <= te_garo) &&
				(tr[j].saero >= t_saero && tr[j].saero <= te_saero) )	{
					count++;
			}	//if


		}	//for j

		if(result < count)	{
			result = count;
			r_garo = t_garo;
			r_saero = te_saero;	//garo and saero it
		}	//result calc..

		}	//for k

	}	//for i

	printf("%d %d\n", r_garo, r_saero);
	printf("%d\n", result);

	return 0;
}

/*
10 6 7 3
2 2
3 4
7 6
4 5
4 3
5 3
6 4
*/
