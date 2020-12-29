#include<bits/stdc++.h>
using namespace std;
int main()
{
	int adj[30][30]={0};
	int i,j,num,n;
	cout<<"Enter value of n ( odd value) :\n";
	cin>>n;
	i=(n-1);
	j=(n-1)/2;
	for(num=1;num<=n*n;num++)
	{
		adj[i][j]=num;
		i++;
		j--;
		if(num%n==0)
		{
			i-=2;
			j++;
		}
		if(i>=n)
			i=0;
		if(j<0)
			j=(n-1);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<setw(5)<<adj[i][j]<<" ";
		cout<<"\n\n";
	}
	return 0;
}
