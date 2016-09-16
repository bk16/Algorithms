#include <iostream>
using namespace std;

int dot(int A[],int B[])
{	
	return A[0]*B[0] + A[1]*B[1];
}

//Compute the dot product AB ⋅ BC
int dot(int A[], int B[], int C[])
{
	int * AB;
	int * BC;
        AB = new int[2];
        BC = new int[2];
        AB[0] = B[0]-A[0];	/* vector AB = VectorB - VectorA*/
        AB[1] = B[1]-A[1];
        BC[0] = C[0]-B[0];
        BC[1] = C[1]-B[1];
        int dot = AB[0] * BC[0] + AB[1] * BC[1];
        return dot;
}

int main()
{
	int A[] = {3,4};
	int B[] = {4,3};

	cout << dot(A,B) << endl;
	return 0;
}

