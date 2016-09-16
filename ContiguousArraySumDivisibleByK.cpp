#include <iostream>
using namespace std;

int main()
{
    int ar[] = {1,2,3,5,4,7};

    int b[3 ];
    for( int i=0; i<6; i++)
        b[i]  = 0;

    b[0]++;
    int sum = 0;
    int k = 3;

    for( int i=0; i<6; i++)
    {
        sum = (sum + ar[i])%k;
        b[sum]++;
    }

    int ans = 0;
    for( int i=0; i<k; i++)
    {
        ans += b[i]*(b[i] - 1)/2;
    }

    cout << "ans : " << ans << endl;
    return 0;
}
