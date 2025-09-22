
#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
const ll mod = 1e9+7;


int32_t main()
{
    fast;
    ll i,t,j,n,b,m;
    vl power(100007);
    
    ll prime=31;// any prime number
    power[0]=1;
    for(i=1;i<100007;i++)
    {
        power[i]=(power[i-1]*prime)%mod;
              //power[0]=prime^0, power[1]=prime^1,power[2]=prime^2...
    }
    string s;
    cin>>s;
    n=s.size();
    vl  hash(n+5,0);

    for(i=0;i<n;i++)
    {
        hash[i+1]=((hash[i]*prime)%mod+s[i])%mod;
    }
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        m=r-l+1;
    //cout<<hash[r]-(hash[l-1]*power[m])<<'\n'; //This way, negative values can be easily
        ll ans= (hash[r]-(hash[l-1]*power[m])%mod +mod)%mod;
        cout<<ans<<'\n';
    }
    return 0;
    
    
    }
    /*
    s=abcejf
    hash[i]=(s[0]⋅p^(i−1)+s[1]⋅p^(i−2)+⋯+s[i−1]⋅p^0)%mod
    hash[0]=0
    hash[1]=a =hash[0]*prime + a
    hash[2]=a*prime+b =hash[1]*prime +b
    hash[3]=a*prime^2 +b*prime +c = hash[2]*priem +c
    hash[4]=a*prime^3 + b*prime^2 + c*prime +e = hash[3]*prime +e
    .......

    hash(l,r)=hash[r]−hash[l−1]⋅p^(r−l+1)
    */

