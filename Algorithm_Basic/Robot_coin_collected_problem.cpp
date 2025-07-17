#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxCoins(vector<vector<int>>& grid) {
    int n = grid.size();         // number of rows
    int m = grid[0].size();      // number of columns

    vector<vector<int>> dp(n, vector<int>(m, 0));  // DP table

    // Base Case: starting cell
    dp[0][0] = grid[0][0];

    // Fill first row
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Fill first column
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Fill the rest of the dp table
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = grid[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n - 1][m - 1];  // Max coins collected at bottom-right
}

int main() {
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {1, 0, 0, 1}
    };

    cout << "Maximum coins collected: " << maxCoins(grid) << endl;

    return 0;
}
