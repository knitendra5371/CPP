#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fptr;
	char str[100];
	fptr=fopen("ayushi.txt","r");
	if(fptr==NULL)
	{
		printf("Error!\n");
		exit(1);
	}
		printf("Enter text : \n");
		while(fgets(str,10,fptr)!=NULL)
		{
			//strcat(str,"\n");
			//fputs(str,fptr);
			puts(str);
		}
		fclose(fptr);
		return 0;
}
