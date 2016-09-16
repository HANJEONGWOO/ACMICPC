#include <stdio.h>

long long int DT[11000][3];
long long int N;
long long int answer;
int value[11000];

int max(int a, int b, int c)
{
	if (b > c) {
		if (a > b)
			return a;
		else
			return b;
	}
	else {
		if (a > c)
			return a;
		else
			return c;
	}
}

void bottom_up(int n) {

	//시작 조건
	DT[1][0] = 0;
	DT[1][1] = value[1];
	DT[1][2] = value[1];

	for (int i = 2; i <= n; i++) {
		DT[i][0] = max(DT[i - 1][0], DT[i - 1][1], DT[i - 1][2]);
		DT[i][1] = DT[i - 1][0] + value[i];
		DT[i][2] = DT[i - 1][1] + value[i];
	}
}

int main(void)
{
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &value[i]);
	}

	bottom_up(N);

	answer = max(DT[N][0], DT[N][1], DT[N][2]);

	printf("%lld\n", answer);

	return 0;
}