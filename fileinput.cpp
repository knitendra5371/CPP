/*function used for file i/o are-
character i/o - fgetc(),fputc(),getc(),,putc()
string  i/o - fgets(),fputs()
formetted i/o - fscanf(),fprintf()*/

//character I/O
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fptr;
	int ch;
	if((fptr=fopen("myfile.txt","w"))==NULL)
	{
		printf("error in opening file\n");
		exit(1);
	}
	printf("enter text\n");
	while((ch=getchar())!=EOF)
		fputc(ch,fptr);
	fclose(fptr);
	return 0;
}
//fgetc()
int main()
{
	FILE *fptr;
	int ch;
	if((fptr=fopen("myfile.txt","r"))==NULL)
	{
		printf("error in opening file\n");
		exit(1);
	}
	while((ch=fgetc(fptr))!=EOF)
		printf("%c",ch);
	fclose(fptr);
	return 0;
}
 
 //string i/o
 //fputs()
 
 int main()
{
	FILE *fptr;
	char str[80];
	if((fptr=fopen("myfile.txt","w"))==NULL)
	{
		printf("error in opening file\n");
		exit(1);
	}
	printf("enter text\n");
	printf("to stop entering, press ctrl+d/ctrl+z\n");
	while(gets(str)!=NULL)
		fputs(str,fptr);
	fclose(fptr);
	return 0;
}

int main()
{
	FILE *fptr;
	char str[80];
	if((fptr=fopen("myfile.txt","w"))==NULL)
	{
		printf("error in opening file\n");
		exit(1);
	}
	printf("enter text\n");
	printf("to stop entering, press ctrl+d/ctrl+z\n");
	while(gets(str)!=NULL)
	{
		strcat(str,"\n");
		fputs(str,fptr);
	}
	fclose(fptr);
	return 0;
}
//fgets()
int main()
{
	FILE *fptr;
	char str[80];
	if((fptr=fopen("myfile.txt","r"))==NULL)
	{
		printf("error in opening file\n");
		exit(1);
	}
	while(fgets(str,80,fptr)!=NULL)
		puts(str);
	fclose(fptr);
	return 0;
}

//fprintf()

struct student
{
	char name[20];
	float marks;
}stu;
int main()
{
	FILE *fptr;
	int i,n;
	if((fptr=fopen("myfile.txt","w"))==NULL)
	{
		printf("error in opening file\n");
		exit(1);
	}
	printf("enter number of records\n");
	scanf("%d",&n);
	for(i=01;i<=n;i++)
	{
		printf("enter name and marks\n");
		scanf("%s%d",stu.name,&stu.marks);
		fprintf(fp,"%s%f",stu.name,stu.marks);
	}
	fclose(fptr);
	return 0;
}

//fscanf()
struct student
{
	char name[20];
	float marks;
}stu;
int main()
{
	FILE *fptr;
	//int i,n;
	if((fptr=fopen("myfile.txt","r"))==NULL)
	{
		printf("error in opening file\n");
		exit(1);
	}
	printf("name\tmarks\n");
	while(fscanf(fp,"%s%f",stu.name,&stu.marks)!=EOF)
		printf("%s\t%f\n",stu.name,stu.marks);
	fclose(fptr);
	return 0;
}

