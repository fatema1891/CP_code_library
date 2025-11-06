//https://atcoder.jp/contests/dp/tasks/dp_f
#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
const ll mod=1e9+7;

string lcs(string s,string t)
{
     ll n=s.size(),m=t.size();
     vll dp(n+1,vl(m+1,0));
     for(int i=1;i<=n;i++)
     {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
     }
    
    string ans="";
    ll i=n,j=m;
    while(i>0&&j>0)
    {
        if(s[i-1]==t[j-1])ans+=s[i-1],i--,j--;
        else if(dp[i-1][j]>dp[i][j-1])i--;
        else j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int32_t main()
{
    fast;
    string s,t;
    cin>>s>>t;
    cout<<lcs(s,t)<<'\n';
} 
/*
input:
fatema
farjn
output:
fa
*/
