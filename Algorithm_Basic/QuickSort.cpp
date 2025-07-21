//QuickSort
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl=vector<ll>;
using vll =vector<vl>;

#define INF 1e9

ll n,i,j;
vl v;

ll partition(vl &v,ll low,ll high)
{
    ll pivot=v[high];
    ll i=low-1;
    for(j=low;j<=high-1;j++)
    {
        if(v[j]<pivot)
        {
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[++i],v[high]);
    return i;

}

void quickSort(vl &v,ll low,ll high)
{
    if(low<high)
    {
        ll pi=partition(v,low,high);//partition index

        quickSort(v,low,pi-1);//sort left side
        quickSort(v,pi+1,high);//sort right side
    }
}

void printArrary()
{
    for(i=0;i<n;i++)cout<<v[i]<<" ";
        cout<<'\n';
}



int main()
{

    cin>>n;
    v.resize(n+5);
    for(i=0;i<n;i++)cin>>v[i];

    cout<<"Original array: ";
    printArrary();

    quickSort(v,0,n-1);

    cout<<"Sorted array : ";
    printArrary();

}
