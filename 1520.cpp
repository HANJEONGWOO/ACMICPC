#include <stdio.h>

int m, n;

int map[550][550];
int dp[550][550];

int wrong(int y, int x)
{
	if(y < 0 || y >= m || x < 0 || x >= n)
		return true;
	else
		return false;
}

int search(int y, int x)
{
	if(dp[y][x])
		return dp[y][x];

	int cnt = 0;

	if(!wrong(y-1, x) && map[y-1][x] > map[y][x])
		cnt += search(y-1, x);
	if(!wrong(y+1, x) && map[y+1][x] > map[y][x])
		cnt += search(y+1, x);
	if(!wrong(y, x-1) && map[y][x-1] > map[y][x])
		cnt += search(y, x-1);
	if(!wrong(y, x+1) && map[y][x+1] > map[y][x])
		cnt += search(y, x+1);

	dp[y][x] = cnt;

	return dp[y][x];

}

int main(void)
{
	int i, j;

	scanf("%d %d", &m, &n);	//input m and n

	dp[0][0] = 1;
	for(i=0; i<m; i++)	{
		for(j=0; j<n; j++)	{
			scanf("%d", &map[i][j]);
		}
	}	//for i

	printf("%d\n", search(m-1, n-1) );	

	return 0;
}
