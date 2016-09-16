#include <iostream>
using namespace std;

int gcd( int a, int b)
{
	if( b == 0 )
	{
		return a;
	}

	return gcd(b, a%b);
}

int lcm(int a,int b)
{
	return b * a/gcd(a,b);
}

int main()
{
	cout << "GCD(24,8) : " << gcd(8,24) << endl;
	cout << "LCM(24,8) : " << lcm(8,24) << endl;
	return 0;
}
