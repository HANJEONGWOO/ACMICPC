#include <stdio.h>

int fruit;
int dir[6];
int far[6];

int map[1010][1010];

int o_y = 500;
int o_x = 500;

int ew_max;
int ew_max_idx;

int sn_max;
int sn_max_idx;

int result;

int main(void)
{
	int i, j, k, l;

	scanf("%d", &fruit);
	
	for(i=0; i<6; i++)	{
		scanf("%d %d", &dir[i], &far[i]);	//direction
	
		if(dir[i] == 1 || dir[i] == 2)	{
			if(ew_max < far[i])	{
				ew_max = far[i];
				ew_max_idx = i;
			}
		}
		else if(dir[i] == 3 || dir[i] == 4)	{
			if(sn_max < far[i])	{
				sn_max = far[i];
				sn_max_idx = i;
			}
		}
	}	//for i

	//far[ew_max_idx] -= 1;
	//far[sn_max_idx] -= 1;	//minus one it
	for(i=0; i<6; i++)	{
		if(dir[i] == 1)	{
			
				for(j=o_x; j<o_x+far[i]; j++)	{
					map[o_y][j] = 2;
				}
				o_x += (far[i]);

			}
			else if(dir[i] == 2)	{

				for(j=o_x; j>o_x-far[i]; j--)	{
					map[o_y][j] = 2;
				}
				o_x -= (far[i]);
			}
			else if(dir[i] == 3)	{

				for(j=o_y; j<=o_y+far[i]; j++)	{
					map[j][o_x] = 2;
				}
				o_y += (far[i]);
			}
			else if(dir[i] == 4)	{

				for(j=o_y; j>o_y-far[i]; j--)	{
					map[j][o_x] = 2;
				}	
				o_y -= (far[i]);	//o
			}
		
				//printf("%d %d\n", o_y, o_x);

	}	//for i

	for(i=0; i<=1000; i++)	{
		for(j=0; j<=1000; j++)	{
			if(map[i][j] == 0)	{
				map[i][j] = 1;
			}
			else if(map[i][j] == 2)	{
				break;
			}
		}
	}

	for(i=1000; i>=0; i--)	{
		for(j=1000; j>=0; j--)	{
			if(map[i][j] == 0)	{
				map[i][j] = 1;
			}
			else if(map[i][j] == 2)	{
				break;
			}
		}
	}

	for(i=0; i<=1000; i++)	{
		for(j=0; j<=1000; j++)	{
			if(map[i][j] == 1)	{
				result++;
			}
		}
	}
	
	result = (1001 * 1001 - result - far[ew_max_idx] - far[sn_max_idx] - 1 ) * fruit;

	printf("%d\n", result);

	return 0;
}

/*
1
1 3
4 3
2 3
3 3

1
4 3
2 3
3 2
1 1
3 1
1 2

1
4 5
2 16
3 3
1 6
3 2
1 10

1
4 50
2 160
3 30
1 60
3 20
1 100
*/
/*
#include<cstdio>
int A,K,x[7],y[7];
int main(){
    scanf("%d",&K);
    for(int i=0;i<6;i++){
        int a,l;
        scanf("%d%d",&a,&l);
        if(a==1)x[i+1]=x[i]+l,y[i+1]=y[i];
        if(a==2)x[i+1]=x[i]-l,y[i+1]=y[i];
        if(a==3)x[i+1]=x[i],y[i+1]=y[i]+l;
        if(a==4)x[i+1]=x[i],y[i+1]=y[i]-l;
    }for(int i=0;i<6;i++)A+=x[i]*y[i+1]-x[i+1]*y[i];
    A=A<0?-A:A;
    printf("%d",A/2*K);
    return 0;
}
*/