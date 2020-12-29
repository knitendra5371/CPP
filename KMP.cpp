#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
void computeLPSArray(char *pat, int M, int *lps);
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0; 
    computeLPSArray(pat, M, lps); 
    int i = 0;
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }
      if (j == M)
      {
        printf("Found pattern at index %d \n", i-j);
        j = lps[j-1];
      }
      else if (i < N && pat[j] != txt[i])
      {
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); 
}
void computeLPSArray(char *pat, int M, int *lps)
{
    int j = 0;  
    int i;
    lps[0] = 0; 
    i = 1;
    while (i < M)
    {
       if (pat[i] == pat[j])
       {
         
         lps[i] = j+1;
         i++;
         j++;
       }
       else 
       {
         if (j == 0)
         {
          lps[i] = 0;
           i++;
           
         }
         else 
         {
          j = lps[j-1];
         }
       }
    }
}
int main()
{
   char *txt="nitendrakumar";
   char *pat = "ra";
   KMPSearch( pat , txt );
   return 0;
}
