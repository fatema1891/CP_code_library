//https://www.spoj.com/problems/FACTCG2/
//this problem must all value and vector integer, 
//can not take long long int because came time limit exceeded.

//must take ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0) or fast  main() ,
//otherwise time limt exceeded

#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
const ll mod=1e9+7;
 
const int N = 3162; // sqrt(1e7);
bitset<N+1>prime_N;
 
vector<int> prime;
 
void sieve()
{
    prime_N.set();
    prime_N[0]=0,prime_N[1]=0;
    for(int i=2;i*i<=N;i++)
    {
        if(prime_N[i])
        {
            for(int j=i*i;j<=N;j+=i)
            {
                prime_N[j]=0;
            }
        }
    }
 
    for(int i=2;i<=N;i++)
    {
        if(prime_N[i])prime.push_back(i);
    }
}
 
void primefact(int n)
{
  cout<<1;
  for(int i:prime)
  {
    if(i*i>n)break;
        while(n%i==0)
        {
            cout<<" x "<<i;
            n/=i;
        }
  }
  if(n>1)cout<<" x "<<n;
    cout<<'\n';
}
 
 
int main() {
    fast;
  int t,i,n,m;
  sieve();
  while(cin>>n)
  {
    primefact(n);
  }
    
  return 0;
} 