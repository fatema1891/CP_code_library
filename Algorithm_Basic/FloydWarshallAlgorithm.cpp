// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl=vector<ll>;
using vll =vector<vl>;

#define INF 1000000007

void floydWarshall(vll &dist)
{
    ll v=dist.size();//number of row = number of column = number of vartex
    

    for(ll k=0;k<v;k++) // Add all vertices one by one to the set of intermediate vertices.
    {
        for(ll i=0;i<v;i++)  // Pick all vertices as source one by one
        {
            for(ll j=0;j<v;j++)   // Pick all vertices as destination for the above picked source
            {
                if(dist[i][k]!=INF && dist[k][j]!=INF)  // shortest path from i to j 
                {
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
}

int main()
{
    ll t,i,j,x,y,n,k,ans;
    vll dist={
        {0, 4, INF, 5, INF},
        {INF, 0, 1, INF, 6},
        {2, INF, 0, 3, INF},
        {INF, INF, 1, 0, 2},
        {1, INF, INF, 4, 0}
    };

        cout<<"the all-pairs shortest path : \n";
        floydWarshall(dist);
        ll v=dist.size();
        for(i=0;i<v;i++)
        {
            for(j=0;j<v;j++)
            {
                cout<<dist[i][j]<<" ";
            }
            cout<<'\n';
        }

        cout<<"distination vartex 2 to 4 : "<<dist[2][4]<<'\n';
}