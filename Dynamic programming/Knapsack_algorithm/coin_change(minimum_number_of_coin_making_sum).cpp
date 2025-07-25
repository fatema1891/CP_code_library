#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl=vector<ll>;
using vll =vector<vl>;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int mod =1e9+7;
const ll INF=1e9+7;

ll minCoin(vl coin,ll n,ll amount)
{
    vl dp(amount+1,INF);
    dp[0]=0;
    for(ll i=1;i<=amount;i++)// amount of money
    {
        for(ll j=0;j<n;j++)  //index of coin 
        {
            if(coin[j]<=i&&dp[i-coin[j]]!=INF)
                dp[i]=min(dp[i],dp[i-coin[j]]+1);
        }
    }

    return dp[amount]==INF?-1:dp[amount];
}


int32_t main()
{
    fast;
    ll n,x,i,j;
    cin>>n>>x;
   vl coin(n+5);
   for(i=0;i<n;i++)cin>>coin[i];

   cout<<minCoin(coin,n,x)<<'\n';

}
