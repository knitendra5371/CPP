#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct point
{
	int x,y;
};
int rotational(point p,point q,point r)
{
	int dom=(r.x-q.x)*(q.y-p.y)-(q.x-p.x)*(r.y-q.y);
	if(dom==0)
		return 0;
	return dom>0?1:2;
}
void ppoint(point hull[],int s)
{
	int i;
	for(i=0;i<s;i++)
		printf("( %d %d )\n",hull[i].x,hull[i].y);
}
void convexhull(point p[],int n)
{
	if(n<3)
	{
		printf("convexhull not possible \n");
		return;
	}
	int l=0,i,j=0;
	for(i=1;i<n;i++)
		if(p[i].x<p[l].x)
			l=i;
	int a=l,b;
	point hull[n];
	do
	{
		hull[j]=p[a];
		j++;
		b=(a+1)%n;
		for(i=0;i<n;i++)
			if(rotational(p[a],p[i],p[b])==2)
				b=i;
			a=b;
	}while(a!=l);
	ppoint(hull,j);
}
int main()
{
	int n;
	printf("Enter number of points\n");
	scanf("%d",&n);
	point p[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	convexhull(p,n);
	return 0;
}
