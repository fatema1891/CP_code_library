//https://www.spoj.com/problems/ETF/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;

const ll mod=1e9+7;
const ll N=1e8+9;
ll phi[N];
bitset<N+1>prime_N;
vl prime;

void phi_1_to_n()
{
    for(ll i=1;i<N;i++)phi[i]=i;
    for(ll i=2;i<N;i++)
    {
        if(phi[i]==i){

        for(ll j=i;j<N;j+=i)phi[j]-=phi[j]/i;
    }
    }
}

ll PHI_V(ll n)
{
    ll coprime=n;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ll c=0;
            while(n%i==0)
            {
                c++;
                n/=i;
            }
            coprime-=coprime/i;
        }
    }
    if(n>1)coprime-=coprime/n;
    return coprime;
}


int32_t main()
{
    fast;
    ll n,t,a,b,x,k;
   /* phi_1_to_n();
   cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<phi[n]<<'\n';  //this procese came time limit exceeded
    }
    */
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<PHI_V(n)<<'\n';
    }
    
}
