#include <iostream>
using namespace std;

/*cross product in the cartesian vectors*/
/* AxB = x1y2 - y2x1*/

int cross(int A[],int B[])
{	
	return A[0]*B[1] + A[1]*B[0];
}

 //Compute the cross product AB x AC
int cross(int A[], int B[], int C[])
{
	int * AB;
	int * AC;
        AB = new int[2];
        AC = new int[2];
        AB[0] = B[0]-A[0];	/* vector AB = VectorB - VectorA*/
        AB[1] = B[1]-A[1];
        AC[0] = C[0]-A[0];
        AC[1] = C[1]-A[1];
        int cross = AB[0] * AC[1] - AB[1] * AC[0];
        return cross;
}

int main()
{
	int A[] = {3,4};
	int B[] = {4,3};

	cout << cross(A,B) << endl;
	return 0;
}

