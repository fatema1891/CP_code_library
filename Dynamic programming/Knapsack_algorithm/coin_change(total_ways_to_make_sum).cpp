
// Function to find the total no. of ways to make the amount by coins

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl=vector<ll>;
using vll =vector<vl>;
#define MOD 1000000007

ll n,w;

ll produceAmount(ll coin[],ll amount)
{
    ll dp[n+5][amount+5],i,j;
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=amount;j++)
        {
            if(i==0&&j==0)dp[i][j]=1;
            else if(i==0&&j>0)dp[0][j]=0;
            else{
           
                if(coin[i]<=j)
                dp[i][j]=dp[i-1][j] + dp[i][j-coin[i]] ;

               else dp[i][j]=dp[i-1][j];//copy previous value
           }
           
            
        }
    }
    return dp[n][amount];
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll t,ans,i,j,amount;
    cin>>n;
    ll coin[n+5];
    //coin[0]=0;
    for(i=1;i<=n;i++)
    {
        cin>>coin[i];
    }

    cin>>amount;
      
    cout<<produceAmount(coin,amount)<<'\n';

}

