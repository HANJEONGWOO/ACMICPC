#include <stdio.h>

int n, a[2200], b[2200], d[2200][2200];

int max(int a, int b)	{
	return a > b ? a : b;
}

int main(void)
{
	int i, j;

	scanf("%d", &n);	//input this

	for(i=0; i<n; i++)	{
		scanf("%d", &a[i]);
	}
	for(i=0; i<n; i++)	{
		scanf("%d", &b[i]);
	}

	for(i=n-1; i>=0; i--)	{
		for(j=n-1; j>=0; j--)	{
			if(a[i] > b[j])
				d[i][j] = d[i][j+1] + b[j];
			else
				d[i][j] = max(d[i+1][j], d[i+1][j+1]);
		}
	}

	printf("%d\n", d[0][0]);

	return 0;
}
