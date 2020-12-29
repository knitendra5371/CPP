// total number of path with k edges;
#include<stdio.h>
#include<stdlib.h>
int n;
int adj[100][100];
int Npath(int s,int d,int k);
void create_graph();
int main()
{
	create_graph();
	int s,d,k;
	printf("Enter source and destination vertex\n");
	scanf("%d%d",&s,&d);
	printf("Enter number of step\n");
	scanf("%d",&k);
	int tpath=Npath(s,d,k);
	printf("%d\n",tpath);
	return 0;
}
int Npath(int u,int d,int k)
{
	int i;;
	if(k<=0)
		return 0;
	if(k==1&&adj[u][d]==1)
		return 1;
	if(k==0&&u==d)
		return 1;
	int count=0;
	if(k>=2)
	{
		for(i=0;i<n;i++)
		{
			if(adj[u][i]==1)
				count+=Npath(i,d,k-1);
		}
	}
	return count;
}
void create_graph()
{
	printf(" Enter number of vertex\n");
	scanf("%d",&n);
	int medges,i,j,origin,destin;
		medges=n*(n-1);
	for(i=1;i<=medges;i++)
	{
		printf(" Enter edge %d (-1 -1 for quit)\n",i);
		scanf("%d%d",&origin,&destin);
		if(origin==-1 && destin==-1)
			break;
		if(origin>=n || destin>=n || origin<0 || destin<0)
		{
			printf("Invalid vertex\n");
			i--;
		}
		else
		{
			adj[origin][destin]=1;
		}
	}
}
