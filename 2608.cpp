#include <stdio.h>
#include <string.h>

int val_array[7] = {1, 5, 10, 50, 100, 500, 1000};
char str_array[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

char s1[30];
char s2[30];
int s1_len;
int s2_len;
int s1_result;
int s2_result;

int prev_state;
int state;	// 0~6 -> 0:1, ~ , 6:M

int result;

int last_array[4];

int main(void)
{
	int i, j;

	scanf("%s %s", &s1, &s2);	//input this

	s1_len = strlen(s1);
	s2_len = strlen(s2);

	prev_state = 6;	//prev_state is six;
	for(i=0; i<s1_len; i++)	{

		if(s1[i] == 'I')	{
			state = 0;
			s1_result += 1;
		}
		else if(s1[i] == 'V')	{
			state = 1;
			s1_result += 5;
		}
		else if(s1[i] == 'X')	{
			state = 2;
			s1_result += 10;
		}
		else if(s1[i] == 'L')	{
			state = 3;
			s1_result += 50;
		}
		else if(s1[i] == 'C')	{
			state = 4;
			s1_result += 100;
		}
		else if(s1[i] == 'D')	{
			state = 5;
			s1_result += 500;
		}
		else if(s1[i] == 'M')	{
			state = 6;
			s1_result += 1000;
		}
		//THIS
		
		if(prev_state < state)	{
			s1_result -= (val_array[prev_state] * 2);	//result minus it !!!
		}

		prev_state = state;	//prev_state it !!!
	}

	prev_state = 6;	//prev_state is six;
	for(i=0; i<s2_len; i++)	{

		if(s2[i] == 'I')	{
			state = 0;
			s2_result += 1;
		}
		else if(s2[i] == 'V')	{
			state = 1;
			s2_result += 5;
		}
		else if(s2[i] == 'X')	{
			state = 2;
			s2_result += 10;
		}
		else if(s2[i] == 'L')	{
			state = 3;
			s2_result += 50;
		}
		else if(s2[i] == 'C')	{
			state = 4;
			s2_result += 100;
		}
		else if(s2[i] == 'D')	{
			state = 5;
			s2_result += 500;
		}
		else if(s2[i] == 'M')	{
			state = 6;
			s2_result += 1000;
		}
		//THIS
		
		if(prev_state < state)	{
			s2_result -= (val_array[prev_state] * 2);	//result minus it !!!
		}

		prev_state = state;	//prev_state it !!!
	}

	result = s1_result + s2_result;
	printf("%d\n", result);

	last_array[0] = result / 1000;
	for(i=0; i<last_array[0]; i++)	{
		printf("M");
	}
	
	result %= 1000;
	last_array[1] = result / 100;
	if(last_array[1] == 9)	{
		printf("CM");
	}
	else if(last_array[1] >= 5)	{
		printf("D");
		
		for(i=0; i<last_array[1]-5; i++)	{
			printf("C");
		}
	}
	else if(last_array[1] == 4)	{
		printf("CD");
	}
	else	{
		for(i=0; i<last_array[1]; i++)	{
			printf("C");
		}

	}	// 0 ~ 3

	result %= 100;
	last_array[2] = result / 10;

	if(last_array[2] == 9)	{
		printf("XC");
	}
	else if(last_array[2] >= 5)	{
		printf("L");
		
		for(i=0; i<last_array[2]-5; i++)	{
			printf("X");
		}
	}
	else if(last_array[2] == 4)	{
		printf("XL");
	}
	else	{
		for(i=0; i<last_array[2]; i++)	{
			printf("X");
		}

	}	// 0 ~ 3


	result %= 10;
	last_array[3] = result;

	if(last_array[3] == 9)	{
		printf("IX");
	}
	else if(last_array[3] >= 5)	{
		printf("V");
		
		for(i=0; i<last_array[3]-5; i++)	{
			printf("I");
		}
	}
	else if(last_array[3] == 4)	{
		printf("IV");
	}
	else	{
		for(i=0; i<last_array[3]; i++)	{
			printf("I");
		}

	}	// 0 ~ 3

	return 0;
}
