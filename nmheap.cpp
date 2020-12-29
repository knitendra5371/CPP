#include<stdio.h>
void extract(int a[100],int i)
{
	int k=a[i];
	int par=i/2;
	while(a[par]<k)
	{
		a[i]=a[par];
		i=par;
		par=i/2;
	}
	a[i]=k;
}
void build_mheap(int a[100],int size)
{
	int i;
	for(i=2;i<=size;i++)
		extract(a,i);
}
int main()
{
	int size;
	scanf("%d",&size);
	int a[100];
	int i,j;
	for(i=1;i<=size;i++)
		scanf("%d",&a[i]);
		build_mheap(a,size);
	for(j=1;j<=size;j++)
		printf("%d ",a[j]);
		return 0;
}
