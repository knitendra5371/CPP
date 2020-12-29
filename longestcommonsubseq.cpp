#include<iostream>
#include<cstring>
using namespace std;
int max(int a,int b){return (a>b)?a:b;}
int lcs(char *x,char *y,int lx,int ly)
{
	int adj[ly+1][lx+1];
	int i,j;
	for(i=0;i<=lx;i++)
		for(j=0;j<=ly;j++)
		{
			if(i==0 || j==0)
				adj[i][j]=0;
			else if(x[i-1]==y[j-1])
				adj[i][j]=adj[i-1][j-1]+1;
			else 
				adj[i][j]= max(adj[i][j-1],adj[i-1][j]);
		}
	return adj[lx][ly];
}
int main()
{
	char x[100],y[100];
	cin.getline(x,100);
	cin.getline(y,100);
	int lx=strlen(x);
	int ly=strlen(y);
	int mlcs=lcs(x,y,lx,ly);
	cout<<mlcs;
	return 0;
}
