#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<float.h>
struct point
{
	int x;
	int y;
};
int compareX(const void*a,const void*b)
{
	int p=((point *)a)->x;
	int q=((point *)b)->x;
	return (p - q);
}
int compareY(const void*a,const void*b)
{
	int p=((struct point *)a)->y;
	int q=((struct point *)b)->y;
	return (p - q);
}
float distance(point p1 , point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
float min(float a,float b)
{
	return a>b?b:a;
}
float bf(point p[],int n)
{
	int i,j;
	float min=FLT_MAX;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if((distance(p[i],p[j]))<min)
				min=distance(p[i],p[j]);
	return min;
}
float stp(point dp[],int size,float d)
{
	qsort(dp, size, sizeof(point),compareY);
	int i,j;
	float min=d;
	for(i=0;i<size;i++)
		for(j=i+1;j<size&&(dp[j].y-dp[i].y)<min;j++)
			if(distance(dp[i],dp[j])<min)
				min=distance(dp[i],dp[j]);
	return min;	
}
float cld(point p[],int n)
{
	if(n<=3)
	return bf(p,n);
	int mid;
	mid=n/2;
	float dl=cld(p,mid);
	float dr=cld(p+mid,n-mid);
	float d=min(dl,dr);
	point dp[n];
	int i,j=0;
	for(i=0;i<n;i++)
		if(abs(p[mid].x - p[i].x) < d)
			dp[j]=p[i],j++;
	return min(d,stp(dp,j,d));
}
float cpd(point p[],int n)
{
	qsort(p,n,sizeof(point),compareX);
	return cld(p,n);
}
int main()
{
	int n,i;
	printf("Enter number of points\n");
	scanf("%d",&n);
	point p[n];
	for(i=0;i<n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	printf("%f ",cpd(p,n));
	return 0;
}
