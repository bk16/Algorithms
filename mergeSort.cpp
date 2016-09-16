#include <iostream>
using namespace std;

void merge(int aux[], int ar[], int lo, int mid, int hi)
{
	for( int i=lo; i<=hi; i++)
		aux[i] = ar[i];

	int i = lo;
	int j = mid + 1;

	for(int k = lo; k<=hi ; k++)
		{
			if( i>mid)	
				ar[k] = aux[j++];
			else if( j> hi)
				ar[k] = aux[i++];
			else if(aux[j] < aux[i]  )
				ar[k] = aux[j++];
			else
				ar[k] = aux[i++];
		}
}

void mergesort(int ar[],int aux[],int lo,int hi)
{
	if( hi<= lo )
		return;	
	int mid = lo + (hi - lo )/2;
	mergesort(ar,aux,lo,mid);
	mergesort(ar,aux,mid+1,hi);
	merge( ar,aux,lo,mid,hi);

}

int main()
{
	int ar[] = {23,6,55,2,12,43,89,41,74};	
	int aux[9];
	mergesort( ar, aux, 0, 8 );

	for( int k : ar )
		cout << k << " " ;
	cout << endl;
}
