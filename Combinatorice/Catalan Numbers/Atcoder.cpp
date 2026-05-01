#include<bits/stdc++.h>
using namespace std;
using ll =long long int ;
using v1=std::vector<ll>;
using v2=vector<v1>;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll N=1e6+7;// without const , ocure error

//catalan number means number of Valid sequences

int32_t main()
{
    ll t,n,m,x,y;
    cin>>n;

   v1 catalan(n+1);
   catalan[0]=1;
   for(ll i=1;i<=n;i++)
   {
    catalan[i]=0;
    for(ll j=0;j<i;j++)
    {
        catalan[i]+=catalan[i-1-j]*catalan[j];//Cn-1 *C0 +Cn-2 *C1 +....+ C0*Cn-1
    }
   }

   cout<<catalan[n]<<'\n';

    return 0;
}
