//https://www.spoj.com/problems/TDPRIMES/
#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
const ll mod=1e9+7;
 
const ll N=1e8;
bitset<N+1>prime_N;  // vector<bool> .. time limit exceeded
                     // bitset : faster and lighter 
vl sieve()
{
  ll c=0;
 // vl prime_N(N+1,1);
  prime_N.set();//all set
  vl prime;
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
 
  for(ll i=2;i<=N;i++)
  {
    if(prime_N[i])prime.push_back(i);
  }
  return prime;
}
 
 
int main() {
  int t,i,n,m;
     vl prime=sieve();
     for(i=0;i<(int)prime.size();i+=100)
     {
      cout<<prime[i]<<'\n';
     }
    
  return 0;
} 