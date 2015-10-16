#include <stdio.h>
 
int coin;   //num of coin
int won;    //purpose coin
int in; //input coin;;;
 
int arr[11000] = {1, 0};    //(0 - 1), (1...end - 0)
 
int main(void)
{
    int i, j;
 
    scanf("%d", &coin); //coin number.
     
    scanf("%d", &won);  //purpose
 
    for(i=0; i<coin; i++)
    {
        scanf("%d", &in);   //in coin
 
        for(j=in; j<=won; j++)
        {
            arr[j] += arr[j-in];
        }
        /*
        for(i=0; i<=won; i++)
            printf("%d ", arr[i]);
        printf("\n");
        */
    }
 
    printf("%d\n", arr[won]);
 
    return 0;
}