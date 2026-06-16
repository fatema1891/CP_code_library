//https://www.hackerrank.com/challenges/maximum-subarray-sum/problem?isFullScreen=true

long maximumSum(vector<long> a, long m) {
   long int ans=0,prefix=0,n=a.size();
   set<long>s;
   for(int i=0;i<n;i++)
   {
    prefix=(prefix+a[i]%m)%m;
    ans=max(ans,prefix);
    
    auto it=s.upper_bound(prefix);
    if(it!=s.end())
    {
        ans=max(ans,((prefix-*it)+m)%m);
    }
    s.insert(prefix);
   }
    return ans;
    
}
