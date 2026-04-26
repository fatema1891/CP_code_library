#include<bits/stdc++.h>
using namespace std;
using ll =long long int ;
using v1=std::vector<ll>;
using v2=vector<v1>;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll N=1e6+7;// without const , ocure error
bool prime[N];

void sieve_Eratosthenes()
{
    memset(prime,false,sizeof(prime));
    for(ll i=3;i*i<=N;i+=2)
    {
        if(prime[i]==false)//is prime
        {
            for(ll j=i*i;j<=N;j+=i+i)
            {
                prime[j]=true;//is not prime
            }
        }
    }
}

bool isPrime(ll n)
{
    if(n<2)return false;
    if(n==2)return true;//is prime
    if(n%2==0)return false;
    return prime[n]==false;//is prime
}

int32_t main()
{
    ll t,n,m,x,y;
    cin>>t;
    sieve_Eratosthenes();
    while(t--)
    {
        cin>>n;
        bool ans=isPrime(n);

        if(ans)cout<<n<<" is prime\n";
        else cout<<n<<" is not prime\n";
    }
    return 0;
}
