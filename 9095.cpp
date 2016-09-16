/*
� ���ڸ� 1, 2, 3�� ������ ���ϴ� ����� ���� ���� ��
���� ����� N�� �ִٸ� (N-1)+1, (N-2)+2, (N-3)+3 ���� ���� �� �� �ִ�.
������ ��츶�� 1, 2, 3�� �����ֱ⸸ �ϸ� N�̶�� ���ڰ� �ϼ��Ǵ� ���̹Ƿ�
���� N�� 1, 2, 3���� ���� �� �ִ� ����� ����
(N-1)�� ���� �� �ִ� ����� �� + (N-2)�� ���� �� �ִ� ����� �� + (N-3)�� ���� �� �ִ� ����� ���� �ؼ� �� �� �ִ�.
*/

#include <stdio.h>

int memo[10 + 1];
int N;
int answer;

int bottom_up(int n) {

	//����
	memo[1] = 1; memo[2] = 2; memo[3] = 4;

	//����
	for (int i = 4; i <= N; i++)
		memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
}

int top_down(int n)
{
	//�ȵǴ� ����
	if (n <= 0) return 0;
	//������ ����
	else if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	else if (n == 3) {
		return 4;
	}
	//�޸������̼�
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