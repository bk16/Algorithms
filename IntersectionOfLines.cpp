#include <iostream>
using namespace std;

/*coefficients for a line are typically integer values, maybe real even*/
bool intersection( int A1,int A2, int B2, int B1,int C1, int C2, double * x, double * y)
{
	double det = A1*B2 - A2*B1;
	if( det == 0 )
		return false;

	*x = (B2*C1 - B1*C2)/det;
	*y = (A1*C2 - A2*C1)/det;

	return true;
}


int main()
{
	double x,y;

	if( !intersection(2,1,1,3,1,2,&x,&y) )
	{
		cout << "Do not intersect!" << endl;
	}
	else
	{
		cout << "X: " << x << endl;
		cout << "Y: " << y << endl;
	}
	return 0;
}
