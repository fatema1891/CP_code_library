//leetcode 3.Longest substring without repeating character

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int32_t main() {
    fast;
    ll i,n,t,j,target;
    string s;
    cin>>s;
    map<char,ll>mp;
    //Total time complexity:O(N*10=> O(N)
    ll l=0,r=0,len=0;
    n=s.size();
    while(r<n)//O(N)
    {
        while(mp[s[r]])//O(1)
        {
            mp[s[l]]=0;
            l++;
        }
        mp[s[r]]=1;
        len=max(len,r-l+1);
        r++;
    }
    cout<<len<<'\n';
}
