/* program for creation of adjacency matrix */
#include<stdio.h>
int main()
{
	printf(" enter number of vertex\n");
	int n;
	scanf("%d",&n);
	int adj[100][100]={0};
	int gtype,origin,destin,medges,i,j;
	printf(" enter 1 for undirected graph and 2 for directed graph\n");
	scanf("%d",&gtype);
	if(gtype==1)
		medges=n*(n-1)/2;
	else
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
			if(gtype==1)
				adj[destin][origin]=1;
		}
	}
	printf("adjacency matrix is : \n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%4d",adj[i][j]);
		printf("\n\n");
	}
	return 0;
}
