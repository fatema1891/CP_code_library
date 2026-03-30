//https://www.spoj.com/problems/COMDIV/
//COMDIV - Number of common divisors
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=vector<ll>;
using vvl=vector<vl>;
const ll mod= 1e9+7;
//#define mx 1e9+7


int32_t main()
{
    fast;
    ll t,i,j;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll c=0,ans=0;
        ll total=1;
        ll n=__gcd(a,b),m=max(a,b);
        for(i=2;i*i<=n;i++)
        {
            ll c=0;
            while(n%i==0&&m%i==0)
            {
                n/=i;
                m/=i;
                c++;
            }
            total*=(c+1);
        }
        if(n>1&&m>1)total*=2;
        cout<<total<<'\n';
    }

}
