#include <stdio.h>

int board;
int open[2];

int visit[22];

int v_len;

int result = 2147483647;

void f(int current, int attempt);
int myabs(int a, int b);

int main(void)
{
	scanf("%d", &board);

	scanf("%d %d", &open[0], &open[1]);

	scanf("%d", &v_len);

	for (int i = 0; i < v_len; i++)
		scanf("%d", &visit[i]); //input visit

	f(0, 0);

	printf("%d\n", result);

	return 0;
}

void f(int current, int attempt)
{
	if (attempt > result)
		return; //end; not good;

	if (current >= v_len) {
		if (attempt < result)
			result = attempt;
	}
	else {
		for (int i = 0; i < 2; i++) {
			int temp = open[i];
			open[i] = visit[current]; //set;;

			f(current + 1, attempt + myabs(temp, visit[current]));

			open[i] = temp; //reset;;;
		}
	}
}

int myabs(int a, int b)
{
	if (a > b) {
		return a - b;
	}
	else {
		return b - a;
	}
}
