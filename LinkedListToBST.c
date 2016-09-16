#include <stdio.h>
#include <stdlib.h>
struct list
{
    int value;
    struct list* next;
};
 
struct node
{
    int value;
    struct node* left;
    struct node* right;
};
 
struct node* newNode(int value);
int countNodes(struct list *head);
struct node* linkedListToBSTUtil(struct list **head, int begin,int end);
 
int countNodes(struct list *head)
{
  int count = 0;
  while(head!=NULL)
  {
    count++;
    head=head->next;
  }
  return count; 
}
 
struct node* newNode(int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = value;
    newnode->left = NULL;
    newnode->right = NULL;
   
    return newnode;
}
struct node* linkedListToBST(struct list *head)
{
    int n = countNodes(head);
    return linkedListToBSTUtil(&head, 0,n-1);
}
 
struct node* linkedListToBSTUtil(struct list **head, int start,int end)
{
    if (start > end)
        return NULL;
     
    int mid = start+(end-start)/2;
    struct list * temp = *head;
    int i = 0;
    while(i<mid && temp->next!=NULL)
    {
        temp = temp->next;
        i++;
    }
    struct node *root = newNode(temp->value);
    root->left = linkedListToBSTUtil(head, start, mid-1);
    root->right = linkedListToBSTUtil(head, mid+1, end);
    return root;
}

void inorder(struct node * root)
{
	if( root != NULL)
	{
		inorder(root->left);
		printf("%d ",root->value);
		inorder(root->right);
	}
}
int main()
{
	int n;
	printf("Enter the value of n\n");
	scanf("%d",&n);

	int i = 0;

	printf("Enter %d values\n",n);

	struct list * head = (struct list *)malloc(sizeof(struct list));
	struct list * temp;
	
	scanf("%d",&(head->value));
	//head->value = i;
	i++;
	head->next = NULL;

	struct list * prev;
	prev = head;
	while( i<n )
	{ 
        	temp =  (struct list *)malloc(sizeof(struct list));
		scanf("%d",&(temp->value));
		temp->next = NULL;

		prev->next = temp;
		prev = temp;

		i++;
		
	}

	temp = head;
	while( temp )
	{
		printf("%d ",temp->value);
		temp = temp-> next;
	}
	printf("\n \n \n");
	struct node * BST = linkedListToBST(head);
	inorder(BST);
	return 0;
}












