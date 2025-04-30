

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int32_t main() {
    fast;
    ll i,n,t,j;
    cin>>n;
    ll a[n+5];
    for(i=0;i<n;i++)cin>>a[i];//array element only 0 and 1;
    //sorting process    //segregate 1 and 0
    // sort(a,a+n); time complexity:O(NlogN)

    //using two pointer  
    ll l=0,r=n-1;
    while(l<r)       //time complexity:O(N)
    {
        if(a[l]==0)
            l++;
        else
        {
            if(a[r]==0)swap(a[l],a[r]),l++,r--;
            else r--;
        }
    }
    for(i=0;i<n;i++)cout<<a[i]<<" ";
        //O(NlogN)>O(N)
}
