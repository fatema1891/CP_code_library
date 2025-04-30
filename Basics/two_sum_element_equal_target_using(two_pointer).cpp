
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int32_t main() {
    fast;
    ll i,n,t,j,target;
    cin>>n;
    ll a[n+5];
    for(i=0;i<n;i++)cin>>a[i];
    cin>>target;
    sort(a,a+n);
    //two sum of element equal target value
    //using two pointer  
    ll l=0,r=n-1,flag=0;
    while(l<r)       //time complexity:O(N)
    {
        ll ans=a[l]+a[r];
        if(ans==target)
            {
                cout<<"true";
                flag=1;
                break;
            }
        else if(ans<target)l++;
        else r--;
    }
    if(flag==0)cout<<"false";
}
