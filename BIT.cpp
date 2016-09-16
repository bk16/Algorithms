#include <iostream>
#include <cstdio>

using namespace std;

int getNext( int j)
{
    int comp = -(j+1);  //bitwise complement of any number n is -(n+1)
    comp++;
    return ((comp&j)+j);
}

int getSum(int idx,int * BIT)
{
    int st = idx + 1;
    int sum = 0;
    while( st > 0 )
    {
        sum += BIT[st];
        st -= ( st & -st);
    }
    return sum;
}

int * getBIT(int ar[], int n)
{
    int * BIT;
    BIT = new int[n+1];
    for( int i=0; i<=n; i++)
        BIT[i] = 0;

    for( int i=0; i<n; i++)
    {
        int j = i+1;
        while( j<=n )
        {
            BIT[j] += ar[i];
            j += ( j & -j);
        }
    }
    return BIT;
}

int main()
{
    int ar[] = {3,2,-1,6,5,4,-3,3,7,2,3};
    int n = 11;

    int * BIT = getBIT(ar,n);
    for( int j=1; j<=n; j++)
        cout << BIT[j] << " ";
    cout << endl;

    cout << "sum 3 : " << getSum(3,BIT) << endl;
    return 0;
}

