#include <iostream>
using namespace std;

/*max prioritiy queue - d ary heap*/
int n;
int d = 4;
void swim(int k,int ar[])
{
	while( k>1 && ar[k/d] < ar[k] )
	{
		int temp = ar[k];
		ar[k] = ar[k/d];
		ar[k/d] = temp;

		k = k/d;
	}
}

void sink(int k,int ar[])
{
	while( d*k <= n )
	{
		int j = d*k;
		if( !(ar[k] < ar[j]) )
			break;
		//if( j<n && ar[j] < ar[j+1])
		//	j++;
		int pos = j;

		for( int i=1; j<n && i<d; i++)
		{
			if( ar[pos] > ar[j+i] )
				pos = j+i;
		}
		j = pos;

		int temp = ar[k];
		ar[k] = ar[j];
		ar[j] = temp;
		
		k = k*d;
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

	insert(23,ar);
	insert(48,ar);
	insert(31,ar);
	insert(5,ar);
	insert(77,ar);
	insert(64,ar);
	insert(32,ar);

	delMax(ar);

	for( int i=1; i<n; i++)
		cout << ar[i] << "  ";

	cout << endl;

	delMax(ar);

	for( int i=1; i<n; i++)
		cout << ar[i] << "  ";

	cout << endl;
}	//insert(


