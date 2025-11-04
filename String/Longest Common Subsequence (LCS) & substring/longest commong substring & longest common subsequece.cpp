#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
using vb=vector<bool>;
const ll mod=1e9+7;

 ll N=1e6+7;
 ll lc_substring(string s,string t)
 {
    ll n=s.size(),m=t.size();
    vll dp(n+1,vl(m+1,0));
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }
            else dp[i][j]=0;
        }
    }
    return ans;
 }

 ll LC_Subsequence(string s,string t)
 {
    ll n=s.size(),m=t.size();
    vll dp(n+1,vl(m+1,0));
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else 
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
 }

int32_t main()
{
    string s,t;
    cin>>s>>t;
    cout<<"longest common substring : "<<lc_substring(s,t)<<'\n';//fa
    cout<<"longest common subsequence : "<<LC_Subsequence(s,t)<<'\n';//faa
    //so all substring is longest common subsequence but all longest common subsequence is not substring

}
