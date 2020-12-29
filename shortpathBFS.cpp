#include<stdio.h>
#include<stdlib.h>
#define max 100
#define nil -1
#define infinity 9999
#define initial 1
#define waiting 2
#define visited 3
int n;
int adj[max][max];
int state[max];
int dist[max];
int pre[max];
void create_graph();
void BF_traversal();
void BFS(int v);
int queue[max],front=-1,rear=-1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();
int main()
{
	int u,v,i,count,path[max];
	create_graph();
	BF_traversal();
	while(1)
	{
		printf("enter destination vertex ( -1 to quit )\n");
		scanf("%d",&v);
		if(v<-1||v>n-1)
		{
			printf("destination vertex does not exist\n");
			continue;
		}
		if(v==-1)
			break;
		count=0;
		if(dist[v]==infinity)
		{
			printf("no path from s to d\n");
			continue;
		}
		else
			printf("shortest distance is: %d\n",dist[v]);
		while(v!=nil)
		{
			count++;
			path[count]=v;
			u=pre[v];
			v=u;
		}
		printf("shortest path is :\n");
		for(i=count;i>1;i--)
			printf(" %d ->",path[i]);
		printf("%d\n",path[i]);
	}
	return 0;
}
void create_graph()
{
	printf(" enter number of vertex\n");
	scanf("%d",&n);
	int medges,i,j,origin,destin;
		medges=n*(n-1);
	for(i=1;i<=medges;i++)
	{
		//printf(" enter edge %d (-1 -1 for quit)\n",i);
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
int isEmpty_queue()
{
	if(front==-1 || front>rear)
		return 1;
	else
		return 0;
}
void insert_queue(int v)
{
	if(rear>=max-1)
		printf("Queue overflow\n");
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
	if(front>rear)
		printf("Queue underflow\n");
	else
		ditem=queue[front];
	front++;
	return ditem;
}
void BF_traversal()
{
	int v;
	for(v=0;v<n;v++)
	{
		state[v]=initial , pre[v]=nil , dist[v]=infinity;
	}
	printf("enter starting vertex for BFS\n");
		scanf("%d",&v);
	BFS(v);
	printf("\n");
}
void BFS(int v)
{
	int i;
	insert_queue(v);
	state[v]=waiting;
	dist[v]=0;
	pre[v]=nil;
	while(!isEmpty_queue())
	{
		v=delete_queue();
		state[v]=visited;
		for(i=0;i<n;i++)
		{
			if(adj[v][i]==1&&state[i]==initial)
			{
				insert_queue(i);
				state[i]=waiting;
				pre[i]=v;
				dist[i]=dist[v]+1;
			}
		}
	}
}
