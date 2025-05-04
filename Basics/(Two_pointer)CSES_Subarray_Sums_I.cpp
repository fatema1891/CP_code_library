 //CSES: (Two pointer ) problem:subarray sums I
//https://cses.fi/problemset/task/1660

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int32_t main() {
    fast;
    ll i,n,s,j;
    cin>>n>>s;
    ll a[n+5];
    for(i=0;i<n;i++)cin>>a[i];
        ll c=0;
      ll l=0,r=0,sum=0;
      while(r<n){
        sum+=a[r];
        while(l<=r&&sum>s)
        {
             sum-=a[l];
             l++;
        }
        if(sum==s)c++;
        r++;
    }
        cout<<c<<'\n';
}
