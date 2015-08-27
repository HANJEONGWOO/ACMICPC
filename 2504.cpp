#include <stdio.h>

char a[33];
char check[33];
int point[33];


int main(void)
{
	int i=0, j=0;

	scanf("%s", &a);	//input

	for( ; a[i]; i++)	{

		if(a[i] == '(')	{
			check[j++] = ')';
		}
		else if(a[i] == '[')	{
			check[j++] = ']';
		}

		if(a[i] == ')')	{
			j--;

			if(j < 0 || check[j] != ')')	{
				point[0] = 0;
				break;
			}
			else	{
				point[j] += 2 * (point[j+1] ? point[j+1] : 1);
				point[j+1] = 0;
			}
		}
		else if(a[i] == ']')	{
			j--;

			if(j < 0 || check[j] != ']')	{
				point[0] = 0;
			}
			else	{
				point[j] += 3 * (point[j+1] ? point[j+1] : 1);
				point[j+1] = 0;
			}
		}

	}
	
	printf("%d\n", point[0]);

	return 0;
}
