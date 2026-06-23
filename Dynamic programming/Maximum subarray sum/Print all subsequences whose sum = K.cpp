
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

void printSumK(int idx, vector<int>& nums,vector<int>& cur,int sum, int K) 
{

    if (idx == nums.size()) {
        if (sum == K) {
            for (int x : cur)
                cout << x << " ";
            cout << "\n";
        }
        return;
    }

    cur.push_back(nums[idx]);
    printSumK(idx + 1, nums, cur, sum + nums[idx], K);

    cur.pop_back();
    printSumK(idx + 1, nums, cur,sum, K);
}

int main()
{
    int n;
    cin>>n;
    
    int k;
    cin>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<int >cur;

   printSumK(0,v,cur,0,k);
}

/*explain:
n=4 ,k=6
arr:5 6 3 1
  5 1
  6
