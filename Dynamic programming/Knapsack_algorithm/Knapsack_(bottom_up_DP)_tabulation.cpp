//Knapsack algorithm
//Using Bottom-Up DP (Tabulation) - O(n x W) Time and Space
// Function to find the maximum value

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl=vector<ll>;
using vll =vector<vl>;
#define MOD 1000000007

ll n,w;

ll knapsack(ll wt[],ll v[],ll w)
{
    ll dp[n+5][w+5],i,j;

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
            if(i==0||j==0)dp[i][j]=0;

            else 
            {
                if(wt[i]<=j)
                dp[i][j]=max(dp[i-1][j], (dp[i-1][j-wt[i]] +v[i] ));

               else dp[i][j]=dp[i-1][j];//copy previous value
            }
        }
    }
    return dp[n][w];
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll t,ans,i,j;
    cin>>n;
    ll weight[n+5],value[n+5];
    //weight[0]=0,value[0]=0;
    
    for(i=1;i<=n;i++)
    {
        cin>>value[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>weight[i];
    }


    cin>>w;// givenWeight;
      
    cout<<knapsack(weight,value,w)<<'\n';

}


/* vector
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl=vector<ll>;
using vll =vector<vl>;
#define MOD 1000000007

ll n,w;

ll knapsack(vl &wt,vl &v,ll w)
{
    vll dp(n+1,vl(w+1));
    ll i,j;

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
            if(i==0||j==0)dp[i][j]=0;

            else 
            {
                if(wt[i-1]<=j)
                dp[i][j]=max(dp[i-1][j], (dp[i-1][j-wt[i-1]] +v[i-1] ));//wt, v started index 0

               else dp[i][j]=dp[i-1][j];//copy previous value
            }
        }
    }
    return dp[n][w];
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll t,ans,i,j;
    cin>>n;
    vl weight(n+1),value(n+1);
    //weight[0]=0,value[0]=0;

    for(i=0;i<n;i++)
    {
        cin>>value[i];
    }
     for(i=0;i<n;i++)
    {
        cin>>weight[i];
    }

    cin>>w;// givenWeight;
      
    cout<<knapsack(weight,value,w)<<'\n';

}    input :n=3
          1 2 3
          4 5 1
          w=4  find output: 3

          */
