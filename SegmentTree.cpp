#include <iostream>
#include <cmath>
using namespace std;

int getMid(int a,int b)
{
    return ( a + (b-a)/2);
}

void updateSegTree(int diff,int * st,int index,int ss,int se,int si)
{
    if( index < ss || index > se )
        return;

    st[si] += diff;

    if( se != ss )
    {
        int mid = getMid(ss,se);
        updateSegTree(diff,st,index,ss,mid,2*si + 1);
        updateSegTree(diff,st,index,mid+1,se,2*si + 2);
    }
}


void updateArray(int ar[], int n, int index, int newval, int * st)
{
    if( index < 0 || index > n-1 )
        return;

    int diff = newval - ar[index];
    ar[index] = newval;

    updateSegTree(diff,st,index,0,n-1,0);
}

int getSum(int * st,int ss, int se,int qs,int qe,int si)
{
    if( ss >= qs && se <= qe )
        return st[si];

    if( se < qs || ss > qe )
        return 0;

    int mid = getMid(ss,se);

    return getSum(st,ss,mid,qs,qe,2*si + 1) + getSum(st,mid+1,se,qs,qe,2*si+2);

}

int getSum(int * st,int n, int qs, int qe )
{
    if( qs < 0 || qe > n-1 || qs > qe )
        return -1;

    return getSum(st,0,n-1,qs,qe,0);
}
int constructSegmentTree(int ar[], int ss, int se, int * st, int si)
{
    if( ss == se )
    {
        st[si] = ar[ss];
        return st[si];
    }

    int mid = getMid(ss,se);
    st[si] = constructSegmentTree(ar,ss,mid,st,2*si + 1)
             + constructSegmentTree(ar,mid+1,se,st,2*si + 2);

    return st[si];
}

int * getSegmentTree(int ar[], int n)
{
    int x = (int)(ceil(log2(n)));

    int maxSize = 2*(int)pow(2,x) - 1;

    int * st = new int[maxSize];

    constructSegmentTree(ar,0,n-1,st,0);

    return st;
}

int main()
{
    int ar[] = {1,3,5,7,9,11};
    int n = 6;
    int * st = getSegmentTree(ar,n);

    int sum = getSum(st,n,2,4);
    cout << sum << endl;

    updateArray(ar,n,3,8,st);
    sum = getSum(st,n,2,4);
    cout << sum << endl;

}
