#include <stdio.h>
#include <stdlib.h>

//works perfect
int N;


typedef struct BST
{
	int val;
	int count;
	struct BST *left, *right;
} node;

node * temp = NULL;
node * head;

node * getNewNode(int val)
{
	node * temp;
	temp = (node *)malloc(sizeof(node));
	temp->val = val;
	temp-> count = 1;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
	
node *  insert( node * root, node * newnode)
{
	//if( newnode->val < root-> val )
	//{
	//	if( root->left == NULL )
	//		root->left = newnode;
	//	else
	//		insert( root->left, newnode);
	//}
	//else if( newnode->val == root->val )
	//	root->count = root->count + 1;
	//
	//else
	//{
	//	if( root->right == NULL )
	//		root->right = newnode;
	//	else
	//		insert( root->right, newnode);
	//}

	if( root == NULL )
		root = newnode;
	else
	{ 	
		if( newnode-> val > root-> val )
		{
			root->right = insert( root->right, newnode);
		}
		else
		{
			root-> left = insert( root->left, newnode);
		}
	}
	return root;
}

void inorder(node * root)
{
	if( root != NULL)
	{	
		inorder(root->left);
		printf("%d ",root->val);
		inorder(root->right);
	}
}

void func(node * root)
{
	if( root != NULL)
	{	
		func(root->left);
		if( temp == NULL )		
		{
			temp = root;
			head = temp;
			temp->left = NULL;
		}
		else
		{
			temp->right = root;
			root->left = temp;
			temp = root;
		}
		func(root->right);
	}
}

void majEl(node * root)
{
	if( root == NULL)
		return;	
	majEl(root->left);
	if( root->count >= N/2 )
		printf("%d is a majority element\n",root->val);
	majEl(root->right);
}
	
int main()
{
	int * ar,n,i;

	printf("Enter the number of items\n");
	
	scanf("%d",&n);
	ar = (int *)malloc(sizeof(int) * n);
	N = n;

	printf("Enter n elements\n");

	for( i=0; i<n ;i++)
		scanf("%d",&ar[i]);



	node * root;
	root = getNewNode(ar[0]);
	
	//printf("I am here\n");
	for( i=1; i<n ;i++)
		root = insert(root, getNewNode(ar[i]));

	//printf("I am here 2\n");
	//inorder(root);
	majEl(root);

	func(root);
	temp = head;
	while( head )
	{
		printf("%d ",head->val);
		head = head->right;
	}
	printf("\n");
	while( temp->right != NULL)
		temp = temp->right;

	while( temp )
	{
		printf("%d ",temp->val);
		temp = temp->left;
	}
	return 0;
}

void printNode(node * n)
{
	printf("Val is %d, count is %d\n",n->val,n->count);
}
	
	
