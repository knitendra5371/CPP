#include<iostream>
using namespace std;
int matrixchainmul( int p[] , int n );
int main()
{
	int n;
	cout<<" Enter size of array\n";
	cin>>n;
	int p[n];
	for( int i=0; i<n; i++ )
		cin>>p[i];
	int mimulop = matrixchainmul( p , n );
	cout<<" minimum multiplication opration : "<<mimulop;
	return 0;
}
int matrixchainmul( int p[] , int n )
{
	int t[n][n];
	for( int i=1; i<=n; i++ )
		t[i][i] = 0;
	int l,j,k,i,min;
	for( l=2; l<n; l++ )
		for( i=1; i<=(n-l+1); i++)
		{
			j = i+l-1;
			t[i][j] = INT_MAX;
			for( k=i; k<=j-1; k++ )
			{
				min = t[i][k] + t[k+1][j] + p[i-1]*p[k]*p[j];
				if(min < t[i][j])
					t[i][j] = min;
			}
		}
	return t[1][n-1];
}
