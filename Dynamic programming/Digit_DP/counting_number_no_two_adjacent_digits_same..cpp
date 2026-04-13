//https://cses.fi/problemset/result/16893125/

#include<bits/stdc++.h>
using namespace std;
using ll=long long int;

ll dp[20][11][2][2];
string s;

ll solve(ll pos,ll prev,ll tight,ll started)
{
    if(pos==s.size())return 1;
    //prev: -1,0,1.....9.(neg ind not allow)=> will index: 0,1,2....10 .so here [prev+1]
    if(dp[pos][prev+1][tight][started]!=-1)return dp[pos][prev+1][tight][started];

    ll ans=0;
    ll limit=tight?(s[pos]-'0'):9;
    for(ll digit=0;digit<=limit;digit++)
    {
        ll new_tight=tight&&(digit==limit);
        ll new_started=started||(digit!=0);
        if(new_started==0)
        {
            ans+=solve(pos+1,-1,new_tight,new_started);
        }
        else
        {
            if(digit==prev)continue;
            ans+=solve(pos+1,digit,new_tight,new_started);
        }
    }
    return dp[pos][prev+1][tight][started]=ans;
}

ll countNum(ll n)
{
    if(n<0)return 0;
    s=to_string(n);
    memset(dp,-1,sizeof(dp));
    return solve(0,-1,1,0);
}


int32_t main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll a,b;
    cin>>a>>b;
    cout<<countNum(b)-countNum(a-1)<<'\n';
}
