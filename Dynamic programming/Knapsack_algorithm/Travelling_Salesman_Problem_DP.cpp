//Travelling Salesman Problem ,all cities visit 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl=vector<ll>;
using vll =vector<vl>;

#define INF 1e9

ll n,i,j;
vll dist,dp;

ll travellingSalesman(ll mask,ll pos)// starting from city `pos` and having visited cities in `mask`
{
    if(mask==(1<<n)-1)  // All cities have been visited, return to starting city (0)
        return dist[pos][0];

    if(dp[mask][pos]!=-1)return dp[mask][pos];

    ll ans=INF;
    for(ll city=0;city<n;city++) //city
    {
      if((mask & (1<<city))==0){
        ll newAns=dist[pos][city] + travellingSalesman(mask | (1<<city), city);
       ans=min(ans,newAns);
        }
    }

    return dp[mask][pos]=ans;
}


int main()
{

    cin>>n;//number of cities
    dist.assign(n+1,vl(n+1));
    dp.assign( 1<<20 ,vl(n+1,-1)); //memset(dp,-1,sizeof(dp)) ; for array

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>dist[i][j];
    }

       ll result= travellingSalesman(1,0) ;// Start from city 0, mask = 1 (only city 0 visited)
    cout << "Minimum cost to visit all cities: " << result << endl;

}
/*
Suppose we have 4 cities:
City 0, City 1, City 2, City 3
Each city can be marked as visited or not visited using 1 bit:
0 means not visited
1 means visited
So, for 4 cities, a bitmask is a 4-bit binary number.

For example:

0000 → No city visited
0001 → Only city 0 visited
1011 → Cities 0, 1, and 3 are visited
1111 → All cities visited

These are just binary representations of an integer, and we’ll use them as mask.
if (mask == (1 << n) - 1)
 Explanation:
(1 << n) means 2^n.

For n = 4:
1 << 4 = 2^4 = 16 = 10000 in binary
(1 << n) - 1 = 2^n - 1 = 15 = 1111 in binary
→ means all cities are visited.

If n = 4, then mask should be 1111 = 15
if (mask == 15) // all 4 cities visited
Then we should return to the starting city (usually city 0).

if ((mask & (1 << city)) == 0)
(1 << city) creates a bitmask where only city-th bit is 1.
mask & (1 << city) checks if that city is already visited.
If result is 0 → city not visited yet

Let’s say:
mask = 5 = 0101 → city 0 and 2 are visited
We check city = 1:
(1 << 1) = 0010
mask & (1 << city) = 0101 & 0010 = 0000 → city 1 not visited
So we enter the if block and try visiting city 1.

int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
 Explanation:
dist[pos][city]: cost from current city to city
mask | (1 << city):
Marks city as visited
Adds that city's bit to the mask
 Example:
Suppose mask = 0101 (cities 0 and 2 visited)
city = 1
mask | (1 << 1) = 0101 | 0010 = 0111 → city 1 now also marked as visited
We now do a recursive call:


input:
4
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0

output:
Minimum cost to visit all cities: 80
*/