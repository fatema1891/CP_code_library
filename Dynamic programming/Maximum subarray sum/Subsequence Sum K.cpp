//https://www.codechef.com/problems/SUBSEQSUMYN

bool existsSubsequence(vector<int>& nums, int n, int k) {
    vector<bool>dp(k+1,false);
    dp[0]=true;//target =0, true;
    for(int x:nums)
    {
        for(int sum=k;sum>=x;sum--)//x>k ,false
        {
            dp[sum]=dp[sum]||dp[sum-x];//logical OR
        }
    }
    return dp[k];
    
}

/*explain:
nums = [2,4,6]
k = 8
Initially:
dp[0] = true
After 2:
0,2
After 4:
0,2,4,6
After 6:
0,2,4,6,8,10,12
Since:
dp[8] = true
Answer = Yes.
*/
