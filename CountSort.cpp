#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
#define MAX 200
using namespace std;

map<int,int> hash;

int search(int a)
{
    return hash[a];
}
bool sorter(int a,int b)
{
    int count1 = search(a);
    int count2 = search(b);

    if( count1 < count2 )
    {
        return false;
    }
    else if( count1 > count2 )
    {
        return true;
    }
    else
    {
        return a < b;
    }
}

int main() {
	//code
	int t;
	scanf("%d",&t);

	while( t-- )
	{
	    int n;
	    scanf("%d",&n);

	    int ar[n];
	    for( int i=0; i<n; i++)
	    {
	        scanf("%d",&ar[i]);
	    }

	    for( int i=0; i<n; i++)
	    {
	        hash[ar[i]]++;
	    }

	    std::sort(ar,ar + n,sorter);

	    for( int i=0; i<n; i++)
	    {
	        printf("%d ",ar[i]);
	    }
	    printf("\n");
	}
	return 0;
}
