//https://www.spoj.com/problems/FIBEZ/

#include<bits/stdc++.h>
using namespace std;
using ll =long long int ;
using v1=std::vector<ll>;
using v2=vector<v1>;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll mod=1e8+7;// without const , ocure error

pair<ll,ll> fib(ll n)
{
    if(n==0)return {0,1};

    auto p=fib(n>>1);//p=n/2

    ll a=p.first;
    ll b=p.second;
    ll c=(a*(((2*b)%mod-a)+mod)%mod)%mod;
    ll d=((a*a)%mod + (b*b)%mod)%mod;

    if(n&1)return {d,(c+d)%mod};
    else return {c,d};

}

int32_t main()
{
    fast;//Without fast ,also come time limit execed
    ll t;
    cin>>t;
    while(t--)
    {
      ll n;
      cin>>n;
      cout<<fib(n).first<<'\n';
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
using ll =long long int ;
using v1=std::vector<ll>;
using v2=vector<v1>;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll mod=1e8+7;// without const , ocure error
const ll MAX=500000;

ll fibo[MAX+5];

void fib()
{
    fibo[0]=0;
    fibo[1]=1;
    for(ll i=2;i<=MAX;i++)
    {
        fibo[i]=(fibo[i-1]+fibo[i-2])%mod;
    }

}

int32_t main()
{
    fast; // Without fast ,also come time limit execed
    ll t;
    cin>>t;
    fib();
    while(t--)
    {
      ll n;
      cin>>n;
      cout<<fibo[n]<<'\n';
    }
    return 0;
}
*/
