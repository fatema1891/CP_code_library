//sum of digit between number L to R 

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0) 
//using ll =long long int;
using vl=std::vector<ll>; 
using vll=vector<vl>;

ll dp[20][2][200];
string s;

ll get_sum(ll pos,bool tight,ll sum)
{
    if(pos==s.size()) return sum;
    if(dp[pos][tight][sum]!=-1) return dp[pos][tight][sum];

    ll ans=0;
    ll limit=tight?(s[pos]-'0'):9;

    for(ll d=0;d<=limit;d++)
    {
        bool new_tight=tight && (d==limit);
        ans+=get_sum(pos+1,new_tight,sum+d);
    }
    return dp[pos][tight][sum]=ans;

}

ll digitDp(ll n)
{
    if(n<0)return 0;
    s=to_string(n);
    memset(dp,-1,sizeof(dp));
    return get_sum(0,1,0);
}


int32_t main()
{
    //fast;
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
    ll R,L;
    cin>>L>>R;
    cout<<digitDp(R)-digitDp(L-1)<<'\n';
}
