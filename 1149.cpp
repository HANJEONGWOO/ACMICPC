#include <stdio.h>
 
int arr[1100][3] = {0};
 
int main(void)
{
    int N;
 
    int i, j;
 
    int r, g, b;
 
    int min;
 
    scanf("%d", &N);
 
    scanf("%d %d %d", &arr[0][0], &arr[0][1], &arr[0][2]);  // 처음
 
    for(i=1; i<N; i++)   {
        scanf("%d %d %d", &r, &g, &b);  // 두번째
 
        arr[i][0] = r + (arr[i-1][1] < arr[i-1][2] ? arr[i-1][1] : arr[i-1][2]);
        arr[i][1] = g + (arr[i-1][0] < arr[i-1][2] ? arr[i-1][0] : arr[i-1][2]); 
        arr[i][2] = b + (arr[i-1][0] < arr[i-1][1] ? arr[i-1][0] : arr[i-1][1]);
    }
 
    min = arr[N-1][0] < arr[N-1][1] ? arr[N-1][0] : arr[N-1][1];
    min = min < arr[N-1][2] ? min : arr[N-1][2];
    //MIN 값 출력
 
    printf("%d\n", min);
 
    return 0;
}