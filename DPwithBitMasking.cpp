#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long solve(int n,vector< vector<int> > v,int dp[][100],int mask,int tid, vector< vector<int> > q)
{
    if( mask == (pow(2,n) -1))
    {
        return dp[mask][tid] = 1;
    }

    if( tid > 100 )
    {
        return 0;
    }

    if( dp[mask][tid] != - 1)
    {
        return dp[mask][tid];
    }

    long long ways = solve(n,v,dp,mask,tid + 1,q) % mod;

    /*for( int j=0; j<v.size(); j++)
    {
        if( find( v[j].begin(),v[j].end(), tid ) != v[j].end() )
        {
            if( mask&(1<<j))
                continue;

            ways = (ways + solve(n,v,dp,(mask | (1<<j)),tid+1))%mod;
        }
    }*/

    int size = q[tid].size();

    for( int j=0; j<size; j++)
    {
        if( mask & ( 1<<q[tid][j] ))
            continue;

        ways += solve(n,v,dp,(mask | 1<<q[tid][j]),tid + 1,q);
        ways %= mod;
    }

    return dp[mask][tid]  = ways;
}

int main()
{
    int t;
    //cin >> t;
    //scanf("%d",&t);

    string str;

    getline(cin ,str );
    t = atoi( str.c_str());



    while( t-- )
    {
        int n;
        //cin >> n;
        //scanf("%d",&n);

        getline(cin ,str );
        n = atoi( str.c_str());

        /*for( int i=0; i<n; i++)
        {
            vector<int> temp;
            getline(cin, str) ;
            str.push_back(' ');

            int pos;

            while( true )
            {
                pos  = str.find(' ');;
                int num = atoi( (str.substr(0,pos)).c_str());
                temp.push_back(num);

                q[num].push_back(i);

                if( pos == str.size() - 1)
                    break;

                str = str.substr(pos + 1);

            }

            v[i] = temp;
        }*/

        vector< vector<int> > v(n);
        vector< vector<int> > q(101);

        for( int i=0; i<n; i++)
        {
            getline(cin, str) ;
            //str.push_back(' ');
            stringstream ss(str);

            //int pos;
            string temp;
            int x;

            while( ss >> temp )
            {
                stringstream s;
                s << temp;
                s >> x;

                q[x].push_back(i);

            }
        }


        /*for( int i=1; i<=100; i++)
        {
            vector<int> temp;
            for( int j=0; j<n; j++)
            {
                if( find( v[j].begin(),v[j].end(), i ) != v[j].end() )
                {
                    temp.push_back(j);
                }
            }
            q[i] = temp;
        }*/

        int dp[1<<n][100];

        for(int i=0; i< (1<<n); i++)
        {
            for( int j=0; j<100; j++)
            {
                dp[i][j] = -1;
            }
        }
        long long ans = solve(n,v,dp,0,1,q);
        cout << (ans) << endl;
    }
    return 0;
}
