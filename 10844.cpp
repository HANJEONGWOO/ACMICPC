#include <stdio.h>

int DT[110][11];
int N;
int answer;

void bottom_up(int n) {

	//시작 조건
	for (int i = 1; i <= 9; i++) {
		DT[1][i] = 1;
	}
	//연산
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			DT[i][j] = 0;
			if (j - 1 >= 0) DT[i][j] += DT[i - 1][j - 1];
			if (j + 1 <= 9) DT[i][j] += DT[i - 1][j + 1];
			DT[i][j] %= 1000000000;
		}
	}
}

int top_down(int n, int l) {

	//안되는 조건
	if (n <= 0 || n == 10)
		return 0;
	//마지막 조건
	else if (n == 1) {
		if (l == 0)
			return 0;
		return 1;
	}
	//메모이제이션
	else {
		if (DT[n][l] != 0)
			return DT[n][l];
		else {
			DT[n][l] = (top_down(n - 1, l - 1) + top_down(n - 1, l + 1)) % 1000000000;
			return DT[n][l];
		}
	}
}

int main(void)
{
	scanf("%d", &N); //input

	bottom_up(N);
	for (int i = 0; i <= 9; i++) {
		answer += DT[N][i];
		answer %= 1000000000;
	}

	printf("%d\n", answer);

	return 0;
}