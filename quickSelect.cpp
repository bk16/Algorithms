
#include <iostream>
using namespace std;

int partition(int ar[],int lo,int hi)
{
	int i = lo;
	int j = hi;

	while( i<j )
	{
		while( ar[i] < ar[lo] )
		{
			i++;
			if( i == hi )
				break;
		}

		while( ar[j] > ar[lo] )
			j--;
		
		if( i>=j )
			break; 

		int temp = ar[i];
		ar[i] = ar[j];
		ar[j] = temp;

	}
	
	int temp = ar[j];
	ar[j] = ar[lo];
	ar[lo] = temp;

	return j;
}
		

void quicksort(int ar[],int lo, int hi)
{	
	if( hi< lo )
		return;
	int j = partition(ar,lo,hi);
	quicksort(ar,lo,j-1);
	quicksort(ar,j+1,hi);
}
int main()
{
	int ar[] = {23,6,55,2,12,43,89,41,74};
	int p = partition(ar,0,8);

	for( int k : ar )
		cout << k << " " ;
	cout << endl;

	cout << "Partition p : " << p << endl;


	quicksort(ar,0,8);

	for( int k : ar )
		cout << k << " " ;
	cout << endl;
	return 0;
}
