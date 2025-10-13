//Sieve, Prime Factorization and Divisors

#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
using vb=vector<bool>;
const ll mod=1e9+7;

 ll N=1e6+7;


vl sieve_N()
{
  vl prime_N(N+1,1);
  vl prime;
  //memset(prime_N,0,prime_N.size());

  for(ll i=2;i*i<=N;i++)
  {
    if(prime_N[i])
    {
      for(ll j=i*i;j<=N;j+=i)
      {
        prime_N[j]=0;
      }
    }
  }

  for(ll i=2;i<N;i++)
  {
    if(prime_N[i])prime.push_back(i);
  }
  return prime;
}

//small prime divisor
vl sieve()
{
  vl prime_N(N+1),prime;
  for(ll i=2;i<=N;i++)
  {
    prime_N[i]=i;
  }

  for(ll i=2;i*i<=N;i++)
  {
    if(prime_N[i]==i)
    {
      for(ll j=i*i;j<=N;j+=i)
      {
        prime_N[j]=min(prime_N[j],i);
      }
    }
  }
  return prime_N;
}

//Largest Prime Factor (LPF)
vl big_div()
{
    vl prime_N(N+1),prime;
  for(ll i=2;i<=N;i++)
  {
    prime_N[i]=i;
  }

  for(ll i=2;i*i<=N;i++)
  {
    if(prime_N[i]==i)
    {
      for(ll j=i;j<=N;j+=i)
      {
        prime_N[j]=i;
      }
    }
  }
  return prime_N;
}

bool prime(ll n)
{
    if(n<2)return false;
    if(n<=3)return true;
    if(n%2==0)return false;
    for(ll i=3;i*i<=n;i+=2)
    {
        if(n%i==0)return false;
    }
    return true;
}

ll primefact(ll n)
{
    ll c=0;             //10=> 2,5
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            c++;
            while(n%i==0)
            {
                n/=i;
            }
            //cout<<i<<' ';
        }
    }
    if(n>1)c++;
    return c;
}

void primeFactorization(ll n)
{
    ll c=0;
    cout<<n<<" => ";  //20
    for(ll i=2;i*i<=n;i++)
    {
        
        if(n%i==0)
        {
            c=0;
            while(n%i==0)
            {
                c++;
                n/=i;
            }
            cout<<i<<"^"<<c<<" , ";
            // or cout<<i<<"^"<<c<<" + ";
        }
    }
    if(n>1)cout<<n<<"^"<<1;
    cout<<'\n';
}


int32_t main()
{
    fast;
    ll i,j,n,t,x,y,z;
    //1. preliminary_test(check n is prime or not)
    cin>>n;
    bool pri=prime(n);
    cout<<n<<(pri?" is prime\n":" is not prime\n");

    //2.number of difference prime factor of n
    cout<<"number of difference prime factor of n = "<<primefact(n)<<'\n';
    

    //3. prime factorization
    //(sum of power of difference prime factor that's are equal of n ) 
    primeFactorization(n);

    //4. saive prime number(count)
    vl ans=sieve_N();
    cout<<ans.size()<<'\n';
    ll pos;
    cin>>pos;
    cout<<ans[pos-1]<<'\n'; //pos th prime number

    // 5. sieve with smallest prime factors (spf) or smallest prime divisor
    vl ans1=sieve();
    cin>>n;
    cout<<ans1[n]<<'\n';//smallest prime divisor the number of n
   
    vl num;//number equal smallest prime divisor or prime factorizatio 
    for(i=2;i<N;i++)
    {
      if(ans1[i]==i)num.push_back(i);
    }


    //6. biggest prime divisor
    vl bigDiv=big_div();
    cin>>n;
    cout<<bigDiv[n]<<'\n';


    
}
