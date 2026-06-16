//https://www.hackerrank.com/challenges/coin-change/problem?isFullScreen=true

//total way to make total_amount

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll getway(ll target_amount,vector<ll>c)
{
    vector<ll>dp(target_amount+1,0);
    dp[0]=1;

    for(ll coin:c)
    {
        for(ll amount=coin;amount<=target_amount;amount++)
            dp[amount]+=dp[amount-coin];
    }
    return dp[target_amount];// total way to make total_amount
}

int main() {
    ll n,target_amount;

    cin>>n>>target_amount;      //n=number of coin
    std::vector<ll>c(n);

    for(int i=0;i<n;i++)cin>>c[i]; //coin

      cout<<getway(target_amount,c)<<'\n';

    return 0;
}
