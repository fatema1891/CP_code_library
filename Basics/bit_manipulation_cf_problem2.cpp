//https://codeforces.com/contest/484/problem/A

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    while (n--) {
        ll l, r;
        cin >> l >> r;

        ll ans=l;
        for(ll i=0;i<=64;i++)
        {
            ll target=ans | (1ll<<i);
            if(target>r)break;

            ans=target;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
