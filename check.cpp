#include <stdio.h>
#include<stdlib.h>
int main()
{
   int n;
   FILE *fptr;
   if ((fptr=fopen("ayushi.txt","w"))==NULL){
       printf("Error! opening file");
       exit(1);         /* Program exits if file pointer returns NULL. */
   }
   fscanf(fptr,"%d",&n);
   printf("Value of n=%d",n); 
   fclose(fptr);   
   return 0;
}
