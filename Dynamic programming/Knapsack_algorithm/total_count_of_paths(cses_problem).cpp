//https://cses.fi/problemset/task/1638

// calculate the number of paths from the upper-left square to the lower-right square.
//count total how many different valid paths can take from start to finish, avoiding traps.

#include<bits/stdc++.h>
using namespace std;
using ll = long long int; 
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll =vector<vl>;
using vc=vector<char>;
using vcc=vector<vc>;
const ll mod =1e9+7;

int32_t main()
{
    ll i,n,k,j;
    cin>>n;
    vcc arr(n+1,vc(n+1));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    vll dp(n+1,vl(n+1,0));
    if(arr[0][0]=='.')dp[0][0]=1;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]=='.')
            {
                if(i>0&&j>0)
                dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;

                if(i==0&&j>0)dp[i][j]=dp[i][j-1]%mod;
               if(j==0&&i>0)dp[i][j]=dp[i-1][j]%mod;
            }

            //else dp[i][j]=0;
        }
    }

    cout<<dp[n-1][n-1]<<'\n';
}