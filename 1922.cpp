#include <stdio.h>
 
#define TEST 0
 
int N, M;   //노드의 수, 간선의 수 : N, M
 
int i, j, k;
int result;
int fail_flag = 0;
int temp;
 
 
 
typedef struct node {
    int s;
    int e;
    int v;
} Node;
int state[101000];  //paste the number
 
 
Node mnode[101000];
 
void quick(Node *mnode, int n);
 
 
int main(void)
{
    scanf("%d %d", &N, &M); //input node
 
    for(i=1; i<=M; i++)
        scanf("%d %d %d", &mnode[i].s, &mnode[i].e, &mnode[i].v);
    //input data start at 1
     
    quick(mnode+1, M);  //quick sort / start 1
 
    if(TEST)    {
        printf("\n");
 
        for(i=1; i<=M; i++)
            printf("%d %d %d\n", mnode[i].s, mnode[i].e, mnode[i].v);
    }
 
    for(i=1; i<=N; i++)
        state[i] = i;   //numbering
 
    for(i=1; i<=M; i++)
    {
        fail_flag = 0;  //fail_flag init
 
        if(state[mnode[i].s] > state[mnode[i].e])    {
            result += mnode[i].v;   //result
            temp = state[mnode[i].e];   //define temp
 
            for(j=1; j<=N; j++)  {   
                if(state[j] == temp)    {   //만약 작은 수라면
                    state[j] = state[mnode[i].s];   //큰 수로 바꾼다.
                }
            }   //for j
        }   //if i
        else if(state[mnode[i].s] < state[mnode[i].e])   {
            result += mnode[i].v;   //result
            temp = state[mnode[i].s];   //define temp
 
            for(j=1; j<=N; j++)  {
                if(state[j] == temp)    {   //만약 작은 수라면
                    state[j] = state[mnode[i].e];
                }   //if
            }   //for j
        }   //else if
 
 
        //check if end
        for(k=1; k<=N; k++)
        {
            if(state[k] != N)   {   //만약 N이 아니라면
                fail_flag = 1;
                break;
            }
        }
 
        if(fail_flag == 0)
            break;
 
        if(TEST)    {
            printf("\n");
            for(k=1; k<=N; k++)
                printf("%d ", state[k]);
        }
 
 
    }   //for i
 
    printf("%d\n", result);
     
    return 0;
}
 
 
 
 
void quick(Node *mnode, int n)
{
    int i, j;
    int mid;
    Node temp;
 
    if(n > 1)
    {
        i = -1;
        j = n-1;
        mid = mnode[n-1].v; //비용 중심으로 정렬
 
        while(1)
        {
            while(mnode[++i].v < mid);   //o rem cha sun
            while(mnode[--j].v > mid);
 
            if(i >= j)
                break;
 
            //swap two value
 
            temp = mnode[i];
            mnode[i] = mnode[j];
            mnode[j] = temp;
 
        }
 
        //swap pivot vaule
        temp = mnode[n-1];
        mnode[n-1] = mnode[i];
        mnode[i] = temp;
 
        //re-quick
        quick(mnode, i);
        quick(mnode+i+1, n-i-1);
    }
 
}