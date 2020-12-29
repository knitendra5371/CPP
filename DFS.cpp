#include<stdio.h>
#include<stdlib.h>
#define max 100
#define initial 1
#define visited 2
int n;
int adj[max][max];
int state[max];
int stack[max];
int top=-1;
void push(int v);
int pop();
int isEmpty_stack();
void DF_traversal();
void DFS(int v);
void create_graph();
int main()
{
	create_graph();
	DF_traversal();
	return 0;
}
void DF_traversal()
{
	int v;
	for(v=0;v<n;v++)
		state[v]=initial;
	printf("enter starting vertex for DFS\n");
		scanf("%d",&v);
	DFS(v);
}
void DFS(int v)
{
	int i;
	push(v);
	while(!isEmpty_stack())
	{
		v=pop();
		if(state[v]==initial)
		{
			printf("%d ",v);
			state[v]=visited;
		}
		for(i=n-1;i>=0;i--)
		{
			if(adj[v][i]==1&&state[i]==initial)
				push(i);
		}
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
void push(int v)
{
	if(top==max-1)
		printf("Stack overflow\n");
	else
	{
		top++;
		stack[top]=v;
	}
}
int pop()
{
	int ditem;
	if(top<=-1)
	{
		printf("Stack underflow\n");
		exit(1);
	}
	else
	{
		ditem=stack[top];
		top--;
		return ditem;
	}
}
int isEmpty_stack()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
