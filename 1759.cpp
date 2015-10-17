#include<cstdio>
#include<algorithm>
 
char s[22];
char t[22];
int n,m;
 
void dfs(int x, int y)
{
	int i;
	if(x == n)
	{
		int j, k;
		j=k=0;
		for(i=0; i<n; i++)
		{
			if(t[i]=='a' || t[i]=='e' || t[i]=='i' || t[i]=='o' || t[i]=='u')
				j++;
			else
				k++;
		}
		if(j>0 && k>1)
			puts(t);
		return;
	}

	for(i=y; s[i];i++)
	{
		t[x] = s[i];
		dfs(x+1, i+1);
	}
}	//dfs

int main()
{
    int i, j;
	int index;
	int temp;

    scanf("%d%d",&n,&m);

    for(i=0;i<m;i++)
		scanf("%s",s+i);
    
	//std::sort(s,s+m);

	for(i=0; i<m-1; i++)
	{
		index = i;
		for(j=i+1; j<m; j++)
		{
			if(s[index] > s[j])	{
				//swap index;
				index = j;
			}
		}
		//swap value
		temp = s[i];
		s[i] = s[index];
		s[index] = temp;
	}

    printf("%s\n", s);

	dfs(0,0);

}