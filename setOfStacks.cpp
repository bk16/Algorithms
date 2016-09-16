#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
	int val;
	struct node * next;
};

class stack
{
private:
	struct node * head;
	int size;

public:
	
	stack()
	{
		head = NULL;
		size = 0;
	}

	stack(int k)
	{
		head = NULL;
		size = 0;
	}

	void push(int item)
	{
		if( head == NULL )
		{
			head = (struct node*)malloc(sizeof(struct node));
			head->val = item;
			head->next = NULL;
		}
		else
		{
			struct node * temp = (struct node*)malloc(sizeof(struct node));
			temp->val = item;
			temp->next = head;
			head = temp;
		}
		size++;
	}

	int pop()
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

	int peek()
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

};

class SetOfStacks
{
private:
	stack stacks[10];
	int capacity;
	int stackNumber;
	int size;

public:
	
	SetOfStacks()
	{
		stackNumber = 0;
		size = 0;
		capacity = 3;
		//stacks = new stack[10];
	}
	
	void push(int e)
	{
		//cout << "stacks[stackNumber].getSize() : " << stacks[stackNumber].getSize() << endl;
		if( stacks[stackNumber].getSize() == capacity )
			stackNumber++;

		stacks[stackNumber].push(e);
		size++;
	}
	
	int pop()
	{
		int e = stacks[stackNumber].pop();
		
		if( stacks[stackNumber].getSize() == 0 )
			stackNumber--;
		size--;
		return e;
	}

	int getSize()
	{
		return size;
	}

	bool empty()
	{
		return size == 0;
	}

	int getStackNUmber()
	{
		return stackNumber;
	}

};
		
int main()
{
	//stack s(2);
	SetOfStacks s;

	s.push(23);
	s.push(41);
	cout << "Stack number : " << s.getStackNUmber() << endl;
	s.push(82);
	s.push(2);

	cout << "Size : " << s.getSize() << endl;
	cout << "Stack number : " << s.getStackNUmber() << endl;
	cout << "Pop : " << s.pop() << endl;
	
	//cout << "Size : " << s.getSize() << endl;
	//cout << "Pop : " << s.pop() << endl;

	s.push(81);
	cout << "Stack number : " << s.getStackNUmber() << endl;
	s.push(93);

	cout << "Stack number : " << s.getStackNUmber() << endl;

	cout << "Size : " << s.getSize() << endl;
	cout << "Pop : " << s.pop() << endl;
	cout << "Size : " << s.getSize() << endl;
}

	
