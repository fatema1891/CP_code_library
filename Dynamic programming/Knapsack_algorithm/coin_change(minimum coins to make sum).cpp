
// Function to find the  Minimum Coins to Make Sum

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl=vector<ll>;
using vll =vector<vl>;
#define MOD 1000000007

ll n,w;

ll produceAmount(ll coin[],ll amount)
{
   ll i,j;
    vll dp(n+1,vl(amount+1,INT_MAX));

    dp[0][0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=amount;j++)
        {
                if(coin[i]<=j)
                dp[i][j]=min(dp[i-1][j] , dp[i][j-coin[i]]+1) ;

               else dp[i][j]=dp[i-1][j];//copy previous value
           
            
        }
    }
    return dp[n][amount];
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll t,ans,i,j,amount;
    cin>>n;
    ll coin[n+5];
    coin[0]=0;
    for(i=1;i<=n;i++)
    {
        cin>>coin[i];
    }

    cin>>amount;
      
    cout<<produceAmount(coin,amount)<<'\n';

}

