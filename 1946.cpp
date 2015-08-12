#include <stdio.h>
#include <stdlib.h>

typedef struct man	{
	int no,data;
}man;

int t;
int n;
int i,j,k,max;

man a[100001];

int b[100001];

typedef int (*compfn)(const void*, const void*);

void quick(man *arr, int n);

int cmp(struct man *p1, struct man *p2)
{

	if(p1->data > p2->data)
		return 1;
	else if(p1->data < p2->data)
		return -1;
	else
		return 0;
}

int main()
{
	scanf("%d",&t);
  
	while(t--)
	{

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      a[i].no=i;
      scanf("%d%d",&a[i].data,&b[i]);
    }
  
	//quick(a, n);
	qsort(a, n, sizeof(man), (compfn)cmp);

    max=100001;
    /*
	for(i=0; i<n; i++)	{
		printf("%d | %d \n", a[i].no, b[i]);
	}
	*/

	k=0;
	for(i=0;i<n;i++)	{
	  if(max>b[a[i].no])
      {
        max=b[a[i].no];	
		//max = b[1] = 4 / b[3] = 3 / b[0] = 2 / b[2] = 1 / b[4] = X
        k++;// 1 / 2 / 3 / 4
      }

    }
  
	printf("%d\n",k);

  }	//while t

  return 0;
}

void quick(man *arr, int n)
{
	int i, j;
	int mid;
	man temp;

	if(n > 1)
	{
		i = -1;
		j = n-1;
		mid = arr[n-1].data;

		while(1)
		{
			while(arr[++i].data < mid);
			while(arr[--j].data > mid);

			if(i >= j)
				break;

			//swap two value
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

		}
		//swap pivot value
		temp = arr[i];
		arr[i] = arr[n-1];
		arr[n-1] = temp;

		//re-quick
		quick(arr, i);
		quick(arr+i+1, n-i-1);
	}	//if
}




/*

2
5
3 2
1 4
4 1
2 3
5 5
7
3 6
7 3
4 2
1 4
5 7
2 5
6 1

1
5
3 2
1 4
4 1
2 3
5 5
*/