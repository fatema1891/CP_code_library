// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl=vector<ll>;
using vll =vector<vl>;

#define INF 1000000007

ll longCommonSubsequence(string &s1,string s2)
{
    ll n=s1.size(),m=s2.size();
    vll dp(n+1,vl(m+1,0));

    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main()
{
    ll t,i,j,x,y,n,k,ans;
    string s1="AGGTAB", s2="GXTXAYB";
    cout<<"longest common subsequence  : "<<longCommonSubsequence(s1,s2)<<'\n';//4

     string st1="FATEMA", st2="FARJANA";
    cout<<"longest common subsequence  : "<<longCommonSubsequence(st1,st2)<<'\n';//3

}