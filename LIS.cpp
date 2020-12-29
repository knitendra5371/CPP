#include<iostream>
using namespace std;
int LIS(int *lcs,int n)
{
	int *tmp;
	tmp=new int[n];
	int i,j;
	for(i=0;i<n;i++)
		tmp[i]=1;
	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
			if(lcs[j]<lcs[i] && tmp[i]<tmp[j]+1)
					tmp[i]=tmp[j]+1;
	int max=0;
	for(i=0;i<n;i++)
		if(max<tmp[i])
			max=tmp[i];
	delete []tmp;
	return max;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int maxl=LIS(arr,n);
	cout<<"longest increasing subsequence : "<<maxl;
	return 0;
}
