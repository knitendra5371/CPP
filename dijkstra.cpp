#include<bits/stdc++.h>
#define max 100
#define temp 0
#define perm 1
#define infinity 9999
#define nil -1
void findpath(int s,int v);
void dijkstra(int s);
int min_temp();
void create_graph();
int n;
int adj[max][max];
int predecessor[max];
int pathlength[max];
int status[max];
int main()
{
	int s,v;
	create_graph();
	printf("enter source vertex\n");
	scanf("%d",&s);
	dijkstra(s);
	while(1)
	{
		printf("enter destination vertex (-1 to quit)\n");
		scanf("%d",&v);
		if(v==-1)
			break;
		if(v<0 || v>=n)
			printf("This vertex does not exist\n");
		else if(v==s)
			printf("Source and destination vertex are same\n");
		else if(pathlength[v]==infinity)
			printf("There is no path from source to destination vertex\n");
		else
			findpath(s,v);
	}
}
void dijkstra(int s)
{
	int i,current;
	for(i=0;i<n;i++)
	{
		predecessor[i]=nil;
		pathlength[i]=infinity;
		status[i]=temp;
	}
	pathlength[s]=0;
	while(1)
	{
		current=min_temp();
		if(current==nil)
			return ;
		status[current]=perm;
		for(i=0;i<n;i++)
		{
			if(adj[current][i]!=0 && status[i]==temp)
				if(pathlength[current]+adj[current][i] < pathlength[i])
				{
					predecessor[i]=current;    
					pathlength[i]= pathlength[current]+adj[current][i];
				}
		}
	}
}
int min_temp()
{
	int i;
	int min=infinity;
	int k=nil;
	for(i=0;i<n;i++)
	{
		if(status[i]==temp && pathlength[i]<min)
		{
			min=pathlength[i];
			k=i;
		}
	}
	return k;
}
void findpath(int s,int v)
{
	int i,u;
	int path[max];
	int shortdist=0;
	int count=0;
	while(v!=s)
	{
		count++;
		path[count]=v;
		u=predecessor[v];
		shortdist+=adj[u][v];
		v=u;
	}
	count++;
	path[count]=s;
	printf("Shortest path is:\n");
	for(i=count;i>=1;i--)
		printf("%d ",path[i]);
	printf("\n Shortest distance is : %d\n",shortdist);
}
void create_graph()
{
	int i,max_edges,origin,destin,wt;
	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges=n*(n-1);
	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d (-1 -1 to quit) :",i);
		scanf("%d %d",&origin,&destin);
		if(origin==-1 && destin==-1)
			break;
		printf("Enter weight for this edge : ");
		scanf("%d",&wt);
		if(origin>=n || destin>=n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
			adj[origin][destin]=wt;
	}
}
