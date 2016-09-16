#include <iostream>
using namespace std;

/*max prioritiy queue*/
int n;
void swim(int k,int ar[])
{
	while( k>1 && ar[k/2] < ar[k] )
	{
		int temp = ar[k];
		ar[k] = ar[k/2];
		ar[k/2] = temp;

		k = k/2;
	}
}

void sink(int k,int ar[])
{
	while( 2*k <= n )
	{
		int j = 2*k;
		if( !(ar[k] < ar[j]) )
			break;
		if( j<n && ar[j] < ar[j+1])
			j++;

		int temp = ar[k];
		ar[k] = ar[j];
		ar[j] = temp;
		
		k = k*2;
	}
}

void insert(int value,int ar[])
{
	ar[n++] = value;
	swim(n-1,ar);
}

void delMax(int ar[])
{
	ar[1] = ar[n-1];
	n--;
	sink(1,ar);
}

int main()
{
	int ar[200];
	n = 1;

	insert(4,ar);
	insert(8,ar);
	insert(7,ar);
	insert(5,ar);
	insert(1,ar);
	insert(6,ar);
	insert(3,ar);	
	for( int i=1; i<n; i++)
		cout << ar[i] << "  ";

	cout << endl;

	delMax(ar);

	for( int i=1; i<n; i++)
		cout << ar[i] << "  ";

	cout << endl;

	delMax(ar);

	for( int i=1; i<n; i++)
		cout << ar[i] << "  ";

	cout << endl;
}	//insert(


