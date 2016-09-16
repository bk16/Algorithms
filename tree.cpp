#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct node
{
	int value;
	struct node * left;
	struct node * right;
};

void insert(struct node ** root, int value)
{
	if( (*root) == NULL )
	{	
		(*root) = (struct node *)malloc(sizeof(struct node));
		(*root)->value = value;
		(*root)->right = NULL;
		(*root)->left = NULL;
		//printf("I am here\n + %d\n",value);
	}
	else
	{
		//printf("I am here 1 + %d\n",value);
		if( (*root)->value > value )
		{
			insert(&((*root)->left),value);
		}
		else
		{
			insert(&((*root)->right),value);
		}
	}
}
int search(struct node ** root, int value)
{
	if( (*root) == NULL )
	{	
		return 0;
		//printf("I am here\n + %d\n",value);
	}
	else
	{
		//printf("I am here 1 + %d\n",value);
		if( (*root)->value > value )
		{
			return search(&((*root)->left),value);
		}
		else if( (*root)->value < value )
		{
			return search(&((*root)->right),value);
		}
		else
		{
			return 1;
		}
	}
}

void del(struct node ** root, int value)
{
	if( (*root) == NULL )
	{	
		return;
		//printf("I am here\n + %d\n",value);
	}
	else
	{
		//printf("I am here 1 + %d\n",value);
		if( (*root)->value > value )
		{
			del(&((*root)->left),value);
		}
		else if( (*root)->value < value )
		{
			del(&((*root)->right),value);
		}
		else
		{
			
			return 1;
		}
	}
}


void inorder(struct node * root )
{
	if( root == NULL )
		return;

	inorder(root->left);
	cout << root->value << " ";
	inorder(root->right);
}
int main()
{
	struct node * root = NULL;
	
	for( int i=0; i<10; i++)
	{
		insert(&root,i+1);
	}

	//cout << root->value;
	inorder(root);

	root = NULL;

	insert(&root,57);
	insert(&root,5);
	insert(&root,23);
	insert(&root,68);
	insert(&root,19);
	insert(&root,109);
	insert(&root,53);
	insert(&root,82);
	insert(&root,65);
	insert(&root,44);
	insert(&root,981);
	insert(&root,44);
	insert(&root,19);

	cout << "search 20 : " << search(&root,23);
	
	cout << endl << endl << endl;
	inorder(root);	
	return 0;
}
