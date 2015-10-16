#include <stdio.h>
 
typedef struct edge {
    int v1;
    int v2;
    int w;
} EDGE;
 
EDGE edge[101000];
int vertex[10100];
int vNum;
int eNum;
int result;
 
void quick(EDGE *myedge, int n);
 
int label(int min, int max)
{
    int cnt = 0;
 
    for(int i=1; i<=vNum; i++)   {
        if(vertex[i] == min)    {
            vertex[i] = max;
        }
 
        if(vertex[i] == vertex[vNum])
            cnt++;
    }
    return cnt;
}
 
int main(void)
{
    int i, j, k;
 
    scanf("%d %d", &vNum, &eNum);
 
    for(i=1; i<=vNum; i++)
        vertex[i] = i;      //정점에 각 번호를 붙임
 
    for(i=0; i<eNum; i++)
        scanf("%d %d %d", &edge[i].v1, &edge[i].v2, &edge[i].w);    //두 간선과 가중치 입력받음
 
    quick(edge, eNum);
     
    for(i=0; i<eNum; i++)    {
        if(vertex[edge[i].v1] != vertex[edge[i].v2])    {
            result += edge[i].w;
 
            int min = vertex[edge[i].v1] < vertex[edge[i].v2] ? vertex[edge[i].v1] : vertex[edge[i].v2];
            int max = vertex[edge[i].v1] > vertex[edge[i].v2] ? vertex[edge[i].v1] : vertex[edge[i].v2];
 
            int count = label(min, max);
 
            if(count == vNum)
                break;
        }
    }
 
    printf("%d\n", result);
 
    return 0;
}
 
void quick(EDGE *myedge, int n)
{
    int i, j;
    int mid;
    EDGE temp;
 
    if(n > 1)
    {
        i = -1;
        j = n-1;
        mid = myedge[n-1].w;
 
        while(1)
        {
            while(myedge[++i].w < mid);
            while(myedge[--j].w > mid);
 
 
            if(i >= j)
                break;
 
            //swap two value
            temp = myedge[i];
            myedge[i] = myedge[j];
            myedge[j] = temp;
 
        }
 
        //swap pivot value;
        temp = myedge[n-1];
        myedge[n-1] = myedge[i];
        myedge[i] = temp;
 
        //re_quick
        quick(myedge, i);
        quick(myedge+i+1, n-i-1);
 
    }   //if
 
}   //end