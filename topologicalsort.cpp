#include<stdio.h>
#include<stdlib.h>
#define max 100
int n;
int adj[max][max];
void create_graph();
int queue[max],front=-1,rear=-1;
void insert_queue(int v);
int delete_queue();
int isEmpty_queue();
int indegree(int v);
int main()
{
	int i,v,count,topo_order[max],indeg[max];
	create_graph();
	for(i=0;i<n;i++)
	{
		indeg[i]=indegree(i);
		if(indeg[i]==0)
			insert_queue(i);
	}
	count=0;
	while(!isEmpty_queue() && count < n)
	{
		v=delete_queue();
		topo_order[++count]=v;
		for(i=0;i<n;i++)
		{
			if(adj[v][i]==1)
			{
				adj[v][i]=0;
				indeg[i]--;
				if(indeg[i]==0)
					insert_queue(i);
			}
		}
	}
	if(count<n)
	{
		printf("no topological ordering possible, graph contains cycle : \n");
		exit(1);
	}
	printf("topological order of vertices :\n");
	for(i=1;i<=count;i++)
	{
		//printf("nitendra....\n");
		printf(" %d",topo_order[i]);
	}
	return 0;
}
int indegree(int v)
{
	int i,in_deg=0;
	for(i=0;i<n;i++)
	{
		if(adj[i][v]==1)
			in_deg++;
	}
	return in_deg;
}
int isEmpty_queue()
{
	if(front==-1 || front>rear)
		return 1;
	else
		return 0;
}
void insert_queue(int v)
{
	if(rear==max-1)
		printf("queue overflow\n");
	else
	{
		if(front==-1)
			front++;
		rear++;
		queue[rear]=v;
	}
}
int delete_queue()
{
	int ditem;
	if(front==-1 || front>rear)
	{
		printf("queue underflow\n");
		exit(1);
	}
	else
	{
		ditem=queue[front];
		front++;
		return ditem;
	}
}
void create_graph()
{
	printf(" enter number of vertex\n");
	scanf("%d",&n);
	int medges,i,j,origin,destin;
		medges=n*(n-1);
	for(i=1;i<=medges;i++)
	{
		printf(" enter edge %d (-1 -1 for quit)\n",i);
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
