#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
	int val;
	struct node * next;
};

class queue
{
private:
	struct node * head;
	struct node * tail;
	int size;

public:
	
	queue()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void enqueue(int item)
	{
		if( head == NULL )
		{
			head = (struct node*)malloc(sizeof(struct node));
			head->val = item;
			head->next = NULL;
			tail = head;
		}
		else
		{
			struct node * temp = (struct node*)malloc(sizeof(struct node));
			temp->val = item;
			temp->next = NULL;
			tail->next = temp;
			tail = tail->next;
		}
		size++;
	}

	int dequeue()
	{
		if( head == NULL )
			exit(0);

		
		int item = head->val;
		head = head->next;

		//if( head == NULL )
		//	tail = NULL;

		size--;
		return item;
	}

	int getSize()
	{
		return size;
	}

	bool empty()
	{
		return size == 0;
	}

	void print()
	{
		struct node * temp = head;
		while( temp )
		{
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main()
{
	queue q;

	q.enqueue(23);
	q.enqueue(41);
	q.enqueue(34);
	q.enqueue(2);

	q.print();

	cout << "Dequeue : " << q.dequeue() << endl;
	
	q.print();	
	cout << "Size : " << q.getSize() << endl;

	cout << "Dequeue : " << q.dequeue() << endl;
	
	q.print();

	q.enqueue(81);
	q.enqueue(93);

	q.print();
	cout << "Size : " << q.getSize() << endl;
	cout << "Dequeue : " << q.dequeue() << endl;
	
	q.print();
}

	
