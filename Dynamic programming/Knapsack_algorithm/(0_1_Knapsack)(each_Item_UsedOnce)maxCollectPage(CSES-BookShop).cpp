//https://cses.fi/problemset/task/1158
//This ensures each item is used once,

#include<bits/stdc++.h>
using namespace std;
using ll = long long int; 
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll =vector<vl>;
using vc=vector<char>;
using vcc=vector<vc>;
const ll mod =1e9+7;


ll maxpage(vl &h,vl &s,ll k,ll n)
{
    ll i,j;
   vl dp(k+5,0);
   for(i=1;i<=n;i++)
   {
    for(j=k;j>=h[i];j--)  //This ensures each item is used once
    {
       dp[j]=max(dp[j],dp[j-h[i]]+s[i]);//each dp[j] on the previous state before current item's update. 
    }                                   //do not overwrite dp[j - h[i]] in the same iteration.
   }
   return dp[k];
}

int32_t main()
{
    ll i,n,k,j;
    cin>>n>>k;
    vl h(n+1);
    vl s(n+1);
    for(i=1;i<=n;i++)cin>>h[i];
    for(i=1;i<=n;i++)cin>>s[i];
        cout<<maxpage(h,s,k,n)<<'\n';

}
