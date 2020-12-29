#include<stdio.h>
int rand(void);
int c;
maxheap(int a[100],int i,int n){
	c++;
	int l=2*i;
	int r=2*i+1;
	int largest;
	if(l<=n&&a[i]<a[l]){
		largest=l;
	}
	else
		largest=i;
		if(r<=n&&a[largest]<a[r])
		largest=r;
		if(i!=largest){
			int t=a[i];
			a[i]=a[largest];
			a[largest]=t;
				maxheap(a,l,n);
		}
}
build_maxheap(int a[100],int n){
	int i;
	for(i=n/2;i>=1;i--){
		maxheap(a,i,n);
		c++;
	}
}
extract(int a[100],int n){
	int max;
	while(n!=0){
	max=a[1];
	a[1]=a[n];
	n--;
//	printf("\n%d",max);
c++;
	maxheap(a,1,n);}
}
int main(){
	
	int t=100;
	FILE *fp;
	fp=fopen("mayank.txt","w");
	while(t--)
   {
	int n;
	c=0;
	n=rand()%100;
	int i,a[100];
	for(i=1;i<=n;i++)
	{
		a[i]=rand()%1000;
	}
	build_maxheap(a,n);
	extract(a,n);
	fprintf(fp,"%d %d\n",n,c);
	}
	/*for(i=1;i<=n;i++){
		//printf("%d ",a[i]);
		printf("\n");
	}*/
	return 0;
}
