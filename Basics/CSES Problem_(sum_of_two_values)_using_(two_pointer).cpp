 //CSES: (Two pointer ) problem:Sum of Two Values
//https://cses.fi/problemset/task/1640

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int32_t main() {
    fast;
    ll i,n,s,j;
    cin>>n>>s;
    std::vector<pair<ll,ll>>a(n);
    for(i=0;i<n;i++)
    {
         cin>>a[i].first;
         a[i].second=i+1;
     }
     sort(a.begin(),a.end());
 i=0,j=n-1;
 while(i<j)
 {
    ll sum=a[i].first+a[j].first;
    if(sum==s)
    {
        cout<<a[i].second<<" "<<a[j].second<<'\n';
        return 0;
    }
   else if(sum<s)i++;
    else j--;
 }
 cout<<"IMPOSSIBLE\n";


}
