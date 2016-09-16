#include <iostream>
#include <cmath>
using namespace std;

bool prime(int n )
{
	if( n == 1 )
		return false;

	if( n== 2 )
		return true;

	if( n%2 == 0 )
		return false;

	for( int i=3; i<sqrt(n); i+=2 )
	{
		if( n%i == 0 )
			return false;
	}
	return true;
}

void sieve(int n)
{
	bool primes[n+1];
	for( int i=0; i<n+1; i++)
		primes[i] = true;

	primes[0] = false;
	primes[1] = false;

	for( int i=2; i<=sqrt(n); i++)
	{
		if( primes[i] )
		{
			for( int k = i*i; k<=n; k+=i )
				primes[k] = false;

			cout << "i : " << i << endl;
		}
	}

	for( int i=1; i<=n; i++)
	{
		if( primes[i] )
			cout << i << " " << endl;
	}
}
/*find prime numbers from 1 to n*/
int main()
{
	cout << prime(23) << endl;
	cout << prime(24) << endl;

	sieve(100);
	return 0;
}


