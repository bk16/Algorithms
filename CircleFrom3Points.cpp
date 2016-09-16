#include <iostream>
#include <cmath>
using namespace std;

struct point
{
	int x;
	int y;
};

struct line
{
	int A;
	int B;
	int C;
};

bool intersection( int A1,int A2, int B1, int B2,int C1, int C2, double * x, double * y)
{
	double det = A1*B2 - A2*B1;
	if( det == 0 )
		return false;

	*x = (B2*C1 - B1*C2)/det;
	*y = (A1*C2 - A2*C1)/det;

	return true;
}

double distance(int A[], int B[])
{
        int d1 = A[0] - B[0];
        int d2 = A[1] - B[1];
        return sqrt(d1*d1+d2*d2);
}

int main()
{
	point P = {0,4};
	point Q = {4,0};
	point R = {0,0};	

	point m1;
	m1.x = (P.x + Q.x)/2;
	m1.y = (P.y + Q.y)/2;

	point m2;
	m2.x = (P.x + R.x)/2;
	m2.y = (P.y + R.y)/2;

	line line1;
	line line2;

	line1.A = Q.y - P.y;
	line1.B = P.x - Q.x;
	line1.C = line1.A*P.x + line1.B*P.y;

	line2.A = R.y - P.y;
	line2.B = P.x - R.x;
	line2.C = line2.A*P.x + line2.B*P.y;

	line line3;
	line line4;

	line3.A = -line1.B;
	line3.B = line1.A;
	line3.C = (-line1.B)*m1.x + line1.A*m1.y;

	line4.A = -line2.B;
	line4.B = line2.A;
	line4.C = (-line2.B)*m2.x + line2.A*m2.y;

	double x,y;
	if( !intersection(line3.A,line4.A,line3.B,line4.B,line3.C,line4.C,&x,&y) )
	{
		cout << "Do not intersect!" << endl;
	}
	else
	{
		cout << "X: " << x << endl;
		cout << "Y: " << y << endl;
	}

	int a[] = {P.x, P.y};
	int b[] =  {(int)x,(int)y};

	cout << "Radius : " << distance(a , b) << endl;


	return 0;
}
	

	
