#include <stdio.h>

int n;
int a[305];
int dp[305][3];

int  max(int a, int b)	{
	if(a >= b)	{
		return a;
	}
	else	{
		return b;
	}

}

int main(void)
{
	int i, j;
	
	scanf("%d", &n);

	for(i=1; i<=n; i++)
		scanf("%d", &a[i]);	//input

	dp[1][1] = dp[1][2] = a[1];

	for(i=2; i<=n; i++)	{
		dp[i][1] = dp[i-1][2] + a[i];
		dp[i][2] = max(dp[i-2][1], dp[i-2][2]) + a[i];
	}

	printf("%d\n", max(dp[n][1], dp[n][2]) );

	return 0;
}