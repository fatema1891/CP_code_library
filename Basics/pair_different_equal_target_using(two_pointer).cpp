
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
    if(target<0)target*=-1;
    ll l=0,r=1,flag=0;
    while(r<n)       //time complexity:O(N)
    {
        ll ans=a[r]-a[l];
        if(ans==target)
            {
                cout<<"true";
                flag=1;
                break;
            }
        else if(ans<target)r++;
        else l++;
        
        if(l==r)r++;

    }
    if(flag==0)cout<<"false";
}
