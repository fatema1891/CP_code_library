#include<bits/stdc++.h>
using namespace std;
using ll =long long int ;
using v1=std::vector<ll>;
using v2=vector<v1>;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll mod=1e9+7;// without const , ocure error

//sum of all subarrays

int32_t main()
{
    ll t,n,m,x,y;
    cin>>t;
    while(t--){
    cin>>n;
    v1 v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ll contribution=v[i]*(i+1)*(n-i);
        ans+=contribution;
    }

   cout<<ans<<'\n';
}

    return 0;
}
/* arr={1,2,3};
subarray=[1],[2],[3],[1,2],[2,3],[1,2,3]
3+8+9=20
*/
