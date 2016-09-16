#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
/*works fine. root is returned with every insert*/
struct node
{
	int value;
	struct node * left;
	struct node * right;
};

struct node * insert(struct node * x, int value)
{
	if( x == NULL )
	{	
		x = (struct node *)malloc(sizeof(struct node));
		x->value = value;
		x->right = NULL;
		x->left = NULL;
	}
	else
	{
		//printf("I am here 1 + %d\n",value);
		if( x->value > value )
		{
			x->left = insert(x->left,value);
		}
		else
		{
			x->right = insert(x->right,value);
		}
	}
	return x;
}
int search(struct node * root, int value)
{
	if( root == NULL )
	{	
		return 0;
		//printf("I am here\n + %d\n",value);
	}
	else
	{
		//printf("I am here 1 + %d\n",value);
		if( root->value > value )
		{
			return search(root->left,value);
		}
		else if( root->value < value )
		{
			return search(root->right,value);
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
struct node * min(struct node * x) 
{ 
        if (x->left == NULL) 
		return x; 
        else                
		return min(x->left); 
} 
struct node * deleteMin(struct node * x) 
{
        if (x->left == NULL) 
		return x->right;
        x->left = deleteMin(x->left);
        return x;
}
struct node * del(struct node * x, int key) 
{
        if (x == NULL) 
		return NULL;

        if (key < x->value)
		x->left  = del(x->left,  key);
        else if (key > x->value) 
		x->right = del(x->right, key);
        else 
	{ 
            if (x->right == NULL) 
			return x->left;
            if (x->left  == NULL) 
			return x->right;
            struct node * t = x;
            x = min(t->right);
            x->right = deleteMin(t->right);
            x->left = t->left;
        } 
        return x;
    } 	

int main()
{
	struct node * root = NULL;
	
	root = insert( root, 23);
	root = insert( root, 3);
	root = insert( root, 41);
	root = insert( root, 87);
	root = insert( root, 8);
	inorder(root);
	
	return 0;
}
