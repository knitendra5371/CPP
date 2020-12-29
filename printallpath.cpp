#include<stdio.h>
#include<stdlib.h>
#define initial 0
#define visite 1
int n;
int adj[100][100];
void create_graph();
void pathall(int s,int d);
void printpath(int s,int d,int path[],int visited[],int index);
int main()
{
	int s,d;
	create_graph();
	printf("Enter source and destination vertex\n");
	scanf("%d%d",&s,&d);
	pathall(s,d);
	return 0;
}
void pathall(int s,int d)
{
	int visited[n];
	int path[n];
	int i,index=0;
	for(i=0;i<n;i++)
		visited[i]=initial;
	printpath(s,d,path,visited,index);
}
void printpath(int u,int d,int path[],int visited[],int index)
{
	int i;
	visited[u]=visite;
	path[index++]=u;
	if(u==d)
	{
		for(i=0;i<index-1;i++)
			printf(" %d -> ",path[i]);
		printf("%d\n",path[i+1]);
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(adj[u][i]==1&&visited[u]!=visite)
				printpath(i,d,path,visited,index);
		}
	}
	index--;
	visited[u]=initial;
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
