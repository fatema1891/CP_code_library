//https://codeforces.com/contest/1527/problem/A

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,l,r,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll c=-1;
        //the position of the highest set bit in binary representation of n.
       // proces:
        while(n)
        {
           c++;
           n=n>>1;
        }
        cout<<(1LL<<c)-1<<'\n';
        /* or highest set bit:
        (1LL<<c) 
        or
        another proces:
        (1<<__lg(n))<<'\n';  //returns the floor of log base 2 of n.
                                  //__lg(5) → floor(log2(5)) = 2 → since 5 is 101 in binary.
        
        or
        res=1;
        while(res*2<n)
        {
          res=res*2;
        }

        */
    }
    
}
