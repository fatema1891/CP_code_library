//https://cses.fi/problemset/task/2064
#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
using vb=vector<bool>;
const ll mod=1e9+7;

 ll N=1e6+7;
vl v(N);
ll modpow(ll a,ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b%2)ans=(ans*a)%mod,b--;
        else a=(a*a)%mod,b/=2;
    }
    return ans%mod;
}
void facto()
{
    v[0]=1;
    for(int i=1;i<N;i++)
    {
        v[i]=(v[i-1]*i)%mod;
    }
}
ll seq(ll n)
{
    if(n%2)return 0;
    ll ans;
    ans=v[n];
    ll k=n/2;
    ll temp=(v[k]*v[k+1])%mod;
    //ans=(ans/temp)%mod;//wrong answer
    ans=(ans*modpow(temp,mod-2))%mod;

    return ans;
}

 
 int32_t main()
 {
    ll t,i,j,n,x;
    cin>>n;
    facto();
    cout<<seq(n)<<'\n';
 }
 /*
 //a^(mod−2)≡a^(−1)  (mod mod); [moduler inverse theoream]
    //here ans= ans* temp^(-1); so temp^(-1) means temp^(mod -2) ,means pow(temp,mod -2)

    // Fermat's theorem :  a^(mod -1) equal 1 ; a^(mod - 1)≡ 1 (mod m) means pow(a,mod-1) equal 1
//a^(mod - 2)≡ a⁻¹ (mod m)
*/