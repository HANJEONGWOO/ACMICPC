#include <stdio.h>
#include <math.h>
 
int f[40] = {1, 0};
int g[40] = {0, 1};
 
int main(void)
{
    int i, j;
    int input;
     
    for(i=2; i<40; i++)  {
        f[i] = f[i-2] + 2*g[i-1];
        g[i] = f[i-1] + g[i-2];
    }
 
    scanf("%d", &input);
 
    printf("%d\n", f[input]);
 
    return 0;
}