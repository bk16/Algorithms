#include <iostream>
using namespace std;

/*min prioritiy queue*/
int n;
void swim(int k,int ar[])
{
	while( k>1 && ar[k/2] > ar[k] )
	{
		int temp = ar[k];
		ar[k] = ar[k/2];
		ar[k/2] = temp;

		k = k/2;
	}
}
/*     while (k > 1 && greater(k/2, k)) {
            exch(k, k/2);
            k = k/2;
        }
    }*/

void sink(int k,int ar[])
{
	while( 2*k <= n )
	{
		int j = 2*k;
		/*if( !(ar[k] > ar[j]) )
			break;*/
		if( j<n && ar[j] > ar[j+1])
			j++;
		if( !(ar[k] > ar[j]) )
			break;
		int temp = ar[k];
		ar[k] = ar[j];
		ar[j] = temp;
		
		k = j	;
	}
}
/* private void sink(int k) {
        while (2*k <= N) {
            int j = 2*k;
            if (j < N && greater(j, j+1)) j++;
            if (!greater(k, j)) break;
            exch(k, j);
            k = j;
        }
    }*/
void insert(int value,int ar[])
{
	ar[++n] = value;
	swim(n,ar);
}
/*   pq[++N] = x;
        swim(N);*/
void delMax(int ar[])
{
	ar[1] = ar[n];
	n--;
	sink(1,ar);
}
/*
	 exch(1, N);
        Key min = pq[N--];
        sink(1);
        pq[N+1] = null; */
int main()
{
	int ar[200];
	n = 0;

	insert(4,ar);
	for( int i=1; i<=n; i++)
		cout << ar[i] << "  ";
	cout << endl;
	insert(8,ar);

	for( int i=1; i<=n; i++)
		cout << ar[i] << "  ";
	cout << endl;
	insert(7,ar);

	for( int i=1; i<=n; i++)
		cout << ar[i] << "  ";
	cout << endl;
	insert(5,ar);

	for( int i=1; i<=n; i++)
		cout << ar[i] << "  ";
	cout << endl;
	insert(1,ar);
	for( int i=1; i<=n; i++)
		cout << ar[i] << "  ";
	cout << endl;
	insert(6,ar);
	for( int i=1; i<=n; i++)
		cout << ar[i] << "  ";
	cout << endl;
	insert(3,ar);
	for( int i=1; i<=n; i++)
		cout << ar[i] << "  ";
	cout << endl;
	for( int i=1; i<=n; i++)
		cout << ar[i] << "  ";

	cout << endl;

	delMax(ar);

	for( int i=1; i<=n; i++)
		cout << ar[i] << "  ";

	cout << endl;

	delMax(ar);

	for( int i=1; i<=n; i++)
		cout << ar[i] << "  ";

	cout << endl;
}	//insert(


