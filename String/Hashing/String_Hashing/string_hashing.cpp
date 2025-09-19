// hash  convert string to integer number
#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
const ll mod = 1e9+7;

ll get_hash(string &s)
{
    ll n=s.size();
    ll prime=3 ; //any prime number sush that power=31
    ll power=1;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ans=(ans+(s[i]*power))%mod;
        power=(power*prime)%mod;
    }
    return ans;
}

int32_t main()
{
    fast;
    ll i,t,j,n,b;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll ans=get_hash(s);
        cout<<ans<<'\n';  
    }   
}
/*hash(s)=s[0]p^0 + s[1]*p^ +......+ s[n-1]*p^(n-1)
p=prime number
s=string
*/