//https://codeforces.com/contest/2218/problem/D

#include<bits/stdc++.h>
using namespace std;
using ll =long long int ;
using v1=std::vector<ll>;
using v2=vector<v1>;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll mod=1e9+7;// without const , ocure error
const ll N=1e6+7;// without const , ocure error
#define M 100000000
int marked[M/64 + 2];


v1 prime;

#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))

void sieve() {
  for (int i = 3; i * i < M; i += 2) {
    if (!on(i)) {
      for (int j = i * i; j <= M; j += i + i) {
        mark(j);
      }
    }
  }
prime.push_back(2);
  for(ll i=3;i<=M;i+=2)
  {
    if(!on(i))prime.push_back(i);
  }
}


int32_t main()
{
    ll t,n,m,x,y;
    cin>>t;
    sieve();
    while(t--){
        cin>>n;
        for(ll i=1;i<=n;i++)
        {
            if(i!=n)cout<<prime[i]*prime[i-1]<<' ';
            else cout<<prime[i]*prime[i-1]<<'\n';
        }
        
    }
    return 0;
}

