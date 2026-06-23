
long long countSubsetSum(vector<int>& a, int K) {
    vector<long long> dp(K + 1, 0);
    dp[0] = 1;

    for (int x : a) {
        for (int s = K; s >= x; s--) {
            dp[s] += dp[s - x];
        }
    }

    return dp[K];
}


/*explain
n=4 k=6
array:5 6 3 1
Valid subsequences:
[6]
[5,1]
Answer = 2
  
