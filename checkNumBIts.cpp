
#include <iostream>
using namespace std;

int main()
{
	int n = 16;
	int i = 16;

	int flag = 0;
	int temp = n;
	while( n!=0 )
	{
		if( n&1 )
			flag++;
		n = n >>1;
	}
	cout << "Flag : " << flag << endl;

	int ans = 0;
	i = 16 + 1;
	while( ans != flag )
	{
		temp = i;
		ans = 0;
		while(temp!=0 )
		{
			if( temp&1 )
				ans++;
			temp = temp >>1;
		}
		i++;
	}
	cout << "Answer : " << i-1 << endl;
	return 0;
}
