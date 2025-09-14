//https://leetcode.com/contest/weekly-contest-467/problems/maximize-sum-of-at-most-k-distinct-elements/

class Solution {
public:
    vector<int> maxKDistinct(vector<int>& num, int k) {
        set<int>st(num.begin(),num.end());
        vector<int>arr(st.begin(),st.end());
        long long int n,i,sum=0;
        n=arr.size();
        if(k>=n)
        {
            sort(arr.rbegin(),arr.rend());
            return arr;
        }
        vector<long long int>pref(n+1,0);
        for(i=0;i<n;i++)
            {
                pref[i+1]=arr[i]+pref[i];
            }
        long long int mx=INT_MIN,l;
        for(i=0;i<=n-k;i++)
            {
                sum=pref[i+k]-pref[i];
                if(sum>mx)
                {
                    l=i;
                    mx=sum;
                }
            }
        vector<int>ans;
        for(i=l;i<l+k;i++)
            {
                ans.push_back(arr[i]);
            }
        sort(ans.rbegin(),ans.rend());
        return ans;
    }

};
