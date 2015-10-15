#include <stdio.h>
 
int arr0[50];
int arr1[50];
 
int main(void)
{
    int N;
    int num;
    int i;
 
    arr0[0] = 1;
    arr1[0] = 0;
 
    arr0[1] = 0;
    arr1[1] = 1;
 
    for(i=2; i<=40; i++)
    {
        arr0[i] = arr0[i-1] + arr0[i-2];
        arr1[i] = arr1[i-1] + arr1[i-2];
    }
     
    scanf("%d", &N);
 
    while(N--)
    {
        scanf("%d", &num);
         
        printf("%d %d\n", arr0[num], arr1[num]);
    }
 
 
    return 0;
}