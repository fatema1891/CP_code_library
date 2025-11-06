//https://codeforces.com/contest/2050/problem/E
#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
using vb=vector<bool>;
const ll mod=1e9+7;

 ll N=1e6+7;

 ll lcs(string a,string b ,string c)
 {
    ll n=a.size(),m=b.size();
    vll dp(n+1,vl(m+1,INT_MAX));
    dp[0][0]=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i>0)
            {
                dp[i][j]=min(dp[i][j], dp[i-1][j]+(a[i-1]!=c[i+j-1]));
            }
            if(j>0)dp[i][j]=min(dp[i][j],dp[i][j-1]+(b[j-1]!=c[i+j-1]));
            
        }
    }
    return dp[n][m];
 }
 
 int32_t main()
 {
    ll t,i,j,n,x;
    cin>>t;
    while(t--)
    {
        string a,b,c;
        cin>>a>>b>>c;
        cout<<lcs(a,b,c)<<'\n';
        
    }
 }
/*a = codes
b = horse
c = codeforces
At each step, we can pick from a or b and compare to c.
 */

 

