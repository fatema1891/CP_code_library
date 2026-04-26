#include<bits/stdc++.h>
using namespace std;
using ll =long long int ;
using v1=std::vector<ll>;
using v2=vector<v1>;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll N=1e6+7;// without const , ocure error
#define M 100000000
int marked[M/64 + 2];

#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))

void sieve(int n) {
  for (int i = 3; i * i < n; i += 2) {
    if (!on(i)) {
      for (int j = i * i; j <= n; j += i + i) {
        mark(j);
      }
    }
  }
}

bool isPrime(int num) {
  return num > 1 && (num == 2 || ((num & 1) && !on(num))); 
}

int32_t main()
{
    ll t,n,m,x,y;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        sieve(n);
        bool ans=isPrime(n);

        if(ans)cout<<n<<" is prime\n";
        else cout<<n<<" is not prime\n";
    }
    return 0;
}
