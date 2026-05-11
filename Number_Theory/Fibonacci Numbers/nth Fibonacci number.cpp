//Fast Doubling Fibonacci algorithm
#include<bits/stdc++.h>
using namespace std;
using ll =long long int ;
using v1=std::vector<ll>;
using v2=vector<v1>;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll mod=1e9+7;// without const , ocure error

pair<ll,ll> fib(ll n)
{
    if(n==0)return {0,1};

    auto p=fib(n>>1);//p=n/2

    ll a=p.first;
    ll b=p.second;
    ll c=a*(2*b-a);
    ll d=a*a + b*b;

    if(n&1)return {d,c+d};
    else return {c,d};

}

int32_t main()
{
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
