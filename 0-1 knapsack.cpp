#include<stdio.h>
int max(int a, int b) { return (a > b)? a : b; }
int knapSack(int mw, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][mw+1];
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= mw; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   } 
   return K[n][mw];
}
int main()
{
	int n,i;
	printf("Enter number of items :\n");
	scanf("%d",&n);
    int val[n];
    int wt[n];
    int mw;
    printf("Enter wt nd val order by :\n");
    for(i=0;i<n;i++)
    {
    	scanf("%d %d",&wt[i],&val[i]);
    }
    printf("Enter max weight :\n");
    scanf("%d",&mw);
    printf(" maximum profit : %d", knapSack(mw, wt, val, n));
    return 0;
}
