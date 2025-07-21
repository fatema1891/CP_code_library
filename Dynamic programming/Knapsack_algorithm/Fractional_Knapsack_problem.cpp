//Fractional Knapsack Problem

#include<bits/stdc++.h>
using namespace std;
using ll =long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;

ll i,n,j;
vl val,wt;

bool compare(vl &a,vl &b)//sort items based on value/weight ratio
{
    double a1=(double)a[0]/a[1];
    double b1=(double)b[0]/b[1];

    return a1>b1; //if(a1>b1)true
} 


ll fractionaKnapsack(vll &items,ll W,ll n)
{
    

    sort(items.begin(),items.end(),compare);
    double totalValue=0.0; // W=currentCapacity

    for(i=0;i<n;i++)
    {
        if(items[i][1]<=W)
        {
            W-=items[i][1];
            totalValue+=items[i][0];
        }
        else
        {
            totalValue+=((double)items[i][0]/items[i][1])*W;
            break;
        }
    }
    return totalValue;
}


int32_t main()
{
    fast;
    cin>>n;
    val.resize(n+1),wt.resize(n+1);
    for(i=0;i<n;i++)cin>>val[i];

    for(i=0;i<n;i++)cin>>wt[i];

    ll capacity;
    cin>>capacity;

    vll items(n,vl(2));
    for(i=0;i<n;i++)
    {
        items[i][0]=val[i];
        items[i][1]=wt[i];
    }

    cout<<"Maximum total value of (Fractional Knapsack) : ";
    cout<<fractionaKnapsack(items,capacity,n)<<'\n';
}
/*Sort items by their value / weight ratio in descending order. If compare(a, b) is true → a comes before b
Otherwise, they are swapped means b comes before a.
The compare function is used by sort() to compare two rows of items, where each row is a vector<int> of two elements:
  compare(items[i], items[j]);   for different i and j
  */

