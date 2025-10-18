/*Euler’s Totient Function (φ(n))

Counts integers ≤ n that are coprime to n.
That means we count all numbers 1, 2, 3, ..., n that have gcd(k, n) = 1.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;

const ll mod=1e9+9;
const ll N=1e5+9;
ll phi[N];

void totient()
{
    for(ll i=1;i<N;i++)
    {
        phi[i]=i;
    }
    for(ll i=2;i<N;i++)
    {
        if(phi[i]==i)
        {
            for(ll j=i;j<N;j+=i)phi[j]-=phi[j]/i;
        }
    }
}

ll PHI(ll n)
{
    ll result=n;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
            }
            result-=result/i;
        }
    }
    if(n>1)result-=result/n;
    return result;
}

int32_t main()
{
    fast;
    totient();//phi_1_to_N
    //for(ll i=1;i<N;i++)cout<<phi[i]<<' ';
        cout<<'\n';

        ll n;
        cin>>n;
    cout<<"coprime "<<n<<" = "<<phi[n]<<'\n';//n=12, coprime 12=4

    // coprime of only number of n
    cout<<"coprime "<<n<<" = "<<PHI(n)<<'\n';//n=12, coprime 12=4
        return 0;
        /*n=12
        gcd(k,n)=1;
        k=> 1 to n={1,2,3,4,5,....,12}
        gcd(1,12)=1,gcd(5,12)=1,gcd(7,12)=1,gcd(11,12)=1;
        so phi(12)=4;number of 4 time gcd =1;
        */

}
