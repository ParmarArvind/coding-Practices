class Solution {
public:
    int dp[301][5001];
    int solve(int i, vector<int>& coins, int currAmount) {
        if (currAmount < 0)
            return 0L;
        if (i >= coins.size()) {
            if (currAmount == 0) {
                return 1L;
            } else
                return 0L;
        }

        if (dp[i][currAmount] != -1) return dp[i][currAmount];
        // take
        int take = solve(i, coins, currAmount - coins[i]);

        // skip
        int skip = solve(i + 1, coins, currAmount);
        
        return dp[i][currAmount] = take + skip;
    }
    

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return solve(0, coins, amount);
    }
};
