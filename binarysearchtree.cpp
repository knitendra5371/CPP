#include<stdio.h>
#include<stdlib.h>
struct node 
{
	struct node *lc;
	int info;
	struct node *rc;
}*root=NULL,*curr;
struct node *create( int d )
{
	struct node *newn;
	newn=( struct node * )malloc( sizeof ( struct node ) );
	newn->lc=NULL;
	newn->rc=NULL;
	newn->info=d;
	return newn;
}
void insert( struct node *curr,int d )
{
	if( root==NULL )
	{
		root=create(d);
	}
	else if(d<curr->info)
	{
		if(curr->lc==NULL)
			curr->lc=create(d);
		else
			insert(curr->lc,d);
	}
	else if(d>curr->info)
	{
		if(curr->rc==NULL)
			curr->rc=create(d);
		else
			insert(curr->rc,d);
	}
}
void preorder(struct node *temp)
{
	if(temp!=NULL)
	{
		printf("%4d",temp->info);
		preorder(temp->lc);
		preorder(temp->rc);
	}
}
void inorder(struct node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->lc);
		printf("%4d",temp->info);
		inorder(temp->rc);
	}
}
void postorder(struct node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->lc);
		postorder(temp->rc);
		printf("%4d",temp->info);
	}
}
int height(struct node *temp)
{
	int lh,rh;
	if(temp==NULL)
		return 0;
	lh=height(temp->lc);
	rh=height(temp->rc);
	if(lh>rh)
		return (1+lh);
	else
		return (1+rh);
}
struct node *maxnode(struct node *temp)
{
	if(temp!=NULL)
		while(temp->rc!=NULL)
			temp=temp->rc;
	return temp;
}
struct node *minnode(struct node *temp)
{
	if(temp!=NULL)
		while(temp->lc!=NULL)
			temp=temp->lc;
	return temp;
}
void search(struct node *temp,int skey)
{
	if(temp==NULL) printf(" search key not exist in binary tree so skey not found\n\n");
	else if(skey==temp->info)
		printf(" search key exist and skey = %d\n\n",temp->info);
	else if(skey<temp->info)
		search(temp->lc,skey);
	else if(skey>temp->info)
		search(temp->rc,skey);
}
int main()
{
	int n,d;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&d);
		curr=root;
		insert((struct node*)curr,d);
	}
	int h;
	struct node *temp,*ptr;
	temp=root;
	preorder(curr);
	printf("\n\n");
	inorder(temp);
	printf("\n\n");
	postorder(temp);
	printf("\n\n");
	h=height(temp);
	printf(" height of binary tree = %4d\n\n",h);
	ptr=maxnode(temp);
	if(ptr!=NULL)
		printf(" maximum node = %4d\n\n",ptr->info);
	else
		printf(" binary tree is empty so maximum node not found\n\n");
	ptr=minnode(temp);
	if(ptr!=NULL)
		printf(" minimum node = %4d\n\n",ptr->info);
	else
		printf(" bonary tree is empty so minimum node not found\n\n");
	printf(" Enter searching key\n\n");
	int k;
	scanf("%d",&k);
	printf("\n");
	search((struct node *)temp,k);
	return 0;
}
