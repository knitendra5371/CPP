#include<stdio.h>
#include<stdlib.h>
int b[100];
build_maxheap(int a[100],int n){
	int i;
	for(i=n/2;i>=1;i--){
		maxheap(a,i,n);
	}
}
maxheap(int a[100],int i,int n){
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
				 t=b[i];
			b[i]=b[largest];
			b[largest]=t;
				maxheap(a,l,n);
		}
}
extract(int a[100],int n,FILE *fp1){
	int max1,max2;
	while(n!=0){
	max1=a[1];
	max2=b[1];
	a[1]=a[n];
	b[1]=b[n];
	n--;
	fprintf(fp1,"%d %d\n",max1,max2);
	maxheap(a,1,n);}
} 
int main()
{
	FILE *fp,*fp1;
	int num1,num2;
	fp=fopen("neet.txt","r");
	fp1=fopen("rit2014057.txt","w");
	int j=1,k=1,a[100],i;
	
	while(fscanf(fp,"%d %d",&num1,&num2)!=EOF)
	{
		a[j]=num1;
		b[k]=num2;
		j++;
		k++;
    }
build_maxheap(a,j-1);
extract(a,j-1,fp1);
//for(i=1;i<j;i++)
	//printf(fp1,"%d\n ",a[i],b[i]);
	fclose(fp1);
	
	
	fclose(fp);
	return 0;
}
