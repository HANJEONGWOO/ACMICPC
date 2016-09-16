/*
어떤 숫자를 1, 2, 3만 가지고 더하는 경우의 수를 구할 때
만약 어떤숫자 N이 있다면 (N-1)+1, (N-2)+2, (N-3)+3 으로 구분 할 수 있다.
각각의 경우마다 1, 2, 3을 더해주기만 하면 N이라는 숫자가 완성되는 것이므로
따라서 N을 1, 2, 3으로 만들 수 있는 경우의 수는
(N-1)을 만들 수 있는 경우의 수 + (N-2)를 만들 수 있는 경우의 수 + (N-3)을 만들 수 있는 경우의 수로 해석 할 수 있다.
*/

#include <stdio.h>

int memo[10 + 1];
int N;
int answer;

int bottom_up(int n) {

	//시작
	memo[1] = 1; memo[2] = 2; memo[3] = 4;

	//연산
	for (int i = 4; i <= N; i++)
		memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
}

int top_down(int n)
{
	//안되는 조건
	if (n <= 0) return 0;
	//마지막 조건
	else if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	else if (n == 3) {
		return 4;
	}
	//메모이제이션
	else {
		if (memo[n] != 0)
			return memo[n];
		else {
			memo[n] = top_down(n - 1) + top_down(n - 2) + top_down(n - 3);
			return memo[n];
		}
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {

		scanf("%d", &N);

		bottom_up(N);
		answer = memo[N];

		printf("%d\n", answer);
	}

	return 0;
}