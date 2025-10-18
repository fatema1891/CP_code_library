
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;

const ll mod=1e9+9;
const ll N=1e5+9;
ll phi[N];

ll perfect_number(ll n)
{
    ll sumDiv=1;
    for(ll i=2;i*i<=n;i++)
    {
        ll c=0;
        if(n%i==0)
        {
            while(n%i==0)
            {
                c++;
                n/=i;
            }
            ll sum=1,power=1;
            for(ll j=0;j<c;j++)
            {
                power*=i;
                sum+=power;
            }
            sumDiv*=sum;
        }
    }
    if(n>1)sumDiv*=(n+1);
    //cout<<sumDiv;
    return sumDiv;
}


int32_t main()
{
    fast;
    ll n;
    cin>>n;
    cout<<(perfect_number(n)==(n*2)?"perfect\n":"is not perfect\n");
    /*
    perfect number means:
    sum of divisors of n == n*2;
    or sum of divisors(without n) of n==n ;
    */

}
