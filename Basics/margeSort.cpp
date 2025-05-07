#include<bits/stdc++.h>
using namespace std;
using ll =long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;

ll i,n,j;
vl v;

vl marge(vl left,vl right)
{
    ll n1=left.size(),n2=right.size();
    vl ans;
    ll l=0,r=0;
    while(l<n1&&r<n2)
    {
        if(left[l]<=right[r])ans.push_back(left[l]),l++;
        else ans.push_back(right[r]),r++;
    }
    while(l<n1)ans.push_back(left[l]),l++;
    while(r<n2)ans.push_back(right[r]),r++;
    return ans;
}

vl margeSort(ll l,ll r)
{
    if(l==r)return {v[l]};
    ll mid=l+(r-l)/2;
    vl left=margeSort(l,mid);
    vl right=margeSort(mid+1,r);
    return marge(left,right);
}

int32_t main()
{
    fast;
    cin>>n;
    v.resize(n);
    for(i=0;i<n;i++)cin>>v[i];

    vl ans=margeSort(0,n-1);

    for(i=0;i<n;i++)cout<<ans[i]<<' ';
}

/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
using vl=std::vector<ll>;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

ll i,j,n;

void marge(ll a[],ll l,ll mid,ll r)
{
    ll n1=mid-l+1,n2=r-mid;
    vl left(n1);
    vl right(n2);
    for(i=0;i<n1;i++)
    {
        left[i]=a[l+i];
    }
    for(i=0;i<n2;i++)
    {
        right[i]=a[mid+1+i];
    }

    i=0,j=0;
    ll k=l;
    while(i<n1&&j<n2)
    {
        if(left[i]<right[j])a[k]=left[i],i++,k++;
        else a[k]=right[j],j++,k++;
    }
    while(i<n1)a[k]=left[i],k++,i++;
    while(j<n2)a[k]=right[j],k++,j++;
}

void margeSort(ll a[],ll l,ll r)
{
    if(l==r)return;
    ll mid=l+(r-l)/2;

    margeSort(a,l,mid);
    margeSort(a,mid+1,r);
    marge(a,l,mid,r);
}

int32_t main()
{
    fast;
    cin>>n;
    ll a[n+5];
    for(i=0;i<n;i++)cin>>a[i];
        margeSort(a,0,n-1);
    for(i=0;i<n;i++)cout<<a[i]<<" ";
    
    
}
*/
