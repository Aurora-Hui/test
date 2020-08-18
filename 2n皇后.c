#include<stdio.h>
#include<stdbool.h>
#include<math.h> 
int a[10][10]={0},i,j,k,n,count=0,tem,max;
int b[10][10];
bool judge1(int x,int y)
{
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(a[i][y]==2&&i!=x)
				return false;
			else if(i!=x&&j!=y&&(x-i==j-y||i-x==j-y)&&a[i][j]==2)
				return false; 
		}
	return true;
}
bool judge2(int x,int y)
{
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(a[i][y]==3&&i!=x)
				return false;
			else if(i!=x&&j!=y&&(x-i==j-y||i-x==j-y)&&a[i][j]==3)
				return false; 
		}
	return true;
}
void dfs2 (int i)
{
	if(i==n+1)
		count++;
	else
	{
		for(int k=1;k<=n;k++)
		{
			if(a[i][k]==1)
			{
				a[i][k]=3;
				if(judge2(i,k))
					dfs2(i+1);
				a[i][k]=1;
			}
		}
	}
	
}      
void dfs1 (int i)
{
	if(i==n+1)
		dfs2(1);
	else
	{
		for(int k=1;k<=n;k++)
		{
			if(a[i][k]==1)
			{
				a[i][k]=2;
				if(judge1(i,k))
					dfs1(i+1);
				a[i][k]=1;
			}
		}
	}
	
}               
int main()
{
	scanf("%d",&n); 
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	dfs1(1);
	printf("%d",count);
	return 0;
}
