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

int main()
{
	cout << "GCD(24,8) : " << gcd(8,24) << endl;
	return 0;
}
