#include <stdio.h>
 
int N;
int arr[110000][3];
 
int comp[4];    //for compare
 
int result;
 
int tc = 1;
 
int minimum(int *arr, int n);
 
int main(void)
{
    int i, j;
 
    while(1)
    {
        scanf("%d", &N);    //input N
 
        if(N == 0)  {
            break;
        }
 
        for(i=0; i<N; i++)   {
            scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
        }   //input this
 
        arr[0][0] = arr[0][1] + 1;  //always bigger
        arr[0][2] += arr[0][1]; //this is transfer
 
        for(i=1; i<N; i++)   {
     
            for(j=0; j<3; j++)   {
                if(j == 0)  {
                    comp[0] = arr[i-1][0];
                    comp[1] = arr[i-1][1];  //comp value
 
                    arr[i][j] += minimum(comp, 2);
                }
                else if(j == 1) {
                    comp[0] = arr[i-1][0];
                    comp[1] = arr[i-1][1];
                    comp[2] = arr[i-1][2];
                    comp[3] = arr[i][0];
 
                    arr[i][j] += minimum(comp, 4);
                }
                else if(j == 2) {
                    comp[0] = arr[i-1][1];
                    comp[1] = arr[i-1][2];
                    comp[2] = arr[i][1];
 
                    arr[i][j] += minimum(comp, 3);  
                }
 
            }   //for j
 
        }   //for i
 
        printf("%d. %d\n", tc, arr[N-1][1]);
        tc++;   //plus tc;
        /*
        for(i=0; i<N; i++)   {
            printf("%d %d %d\n", arr[i][0], arr[i][1], arr[i][2]);
        }
        */
    }
 
 
    return 0;
}
 
int minimum(int *arr, int n)
{
    int i;
    int min = arr[0];
 
    for(i=1; i<n; i++)   {
        if(arr[i] < min) {
            min = arr[i];   //trans it
        }
    }
 
    return min; //return
}
/*
4
13 7 5
7 13 6
14 3 12
15 6 16
4
-13 7 -5
-7 -13 -6
-14 -3 -12
-15 6 -16
0
 
*/