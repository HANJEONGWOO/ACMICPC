#include <stdio.h>

int memo[1000000];
int N;
int answer;

int min(int a, int b, int c)
{
	if (a > b) {
		if (b > c)
			return c;
		else
			return b;
	}
	else {
		if (a > c)
			return c;
		else
			return a;
	}
}

void bottom_up(int n) {

	//��������
	memo[1] = 0;

	//����
	for (int i = 2; i <= N; i++) {
		memo[i] = memo[i - 1] + 1;
		if (i % 2 == 0 && memo[i] > memo[i / 2] + 1)
			memo[i] = memo[i / 2] + 1;
		if (i % 3 == 0 && memo[i] > memo[i / 3] + 1)
			memo[i] = memo[i / 3] + 1;
	}
}

int top_down(int n) {

	//�ȵǴ� ����
	if (n < 0)
		return 1;
	else if (n == 1)
		return 0;
	else {
		if (memo[n] != 0) //�޸� ���� �ִٸ�
			return memo[n];
		else { //�޸� ���� ���ٸ�
			int temp;
			//-1�� ������ ���ϰ� �� ��찡 �����Ƿ� ���� ��
			memo[n] = top_down(n - 1) + 1;
			if (n % 2 == 0) {
				temp = top_down(n / 2) + 1;
				if (memo[n] > temp) memo[n] = temp;
			}
			if (n % 3 == 0) {
				temp = top_down(n / 3) + 1;
				if (memo[n] > temp) memo[n] = temp;
			}
			return memo[n];
		}
	}
}

int main(void) {

	//�Է�
	scanf("%d", &N);

	bottom_up(N);

	answer = memo[N];

	printf("%d\n", answer);

	return 0;
}