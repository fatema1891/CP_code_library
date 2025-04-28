
//Educational Codeforces Round 93 (Rated for Div. 2)  C. Good Subarrays

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int32_t main() {
    fast;
    ll t,i;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        map<ll,ll>mp;
        mp[0]=1;
        ll ans=0,sum=0,ind=0;
        for(i=0;i<n;i++)
        {
            sum+=s[i]-'0';
            ind=sum-(i+1);
            ans+=mp[ind];
            mp[ind]++;
        }
        cout<<ans<<'\n';
    }
}
