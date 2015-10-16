#include <stdio.h>
 
int N;  //n num
int purpose;    //purpose won
int coin;   //coin value
 
int arr[11000] = {0};   //array for coin
 
int main(void)
{
    int i, j;
 
    scanf("%d %d", &N, &purpose);   //input
 
    for(i=0; i<11000; i++)
        arr[i] = 2000000000;
    arr[0] = 0;
 
    while(N--)
    {
        scanf("%d", &coin); //input coin
 
        for(i=coin; i<=purpose; i++)
        {
            if(arr[i-coin]+1 < arr[i])
                arr[i] = arr[i-coin] + 1;
        }
    }
    if(arr[purpose] == 2000000000)
        printf("-1\n");
    else
        printf("%d\n", arr[purpose]);
 
    return 0;
}
/*
3 15
1
5
12
*/