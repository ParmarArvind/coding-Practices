class Solution {
public:
    int n;
    int dp[1001];
    int solve(vector<int>&cost ,int curr)
    {
        if(curr>=n) return 0;
        if(dp[curr] != -1) return dp[curr];
        return dp[curr]=cost[curr]+min(solve(cost,curr+1),solve(cost , curr+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        memset(dp,-1,sizeof(dp));
        return min(solve(cost,0),solve(cost,1));
    }
};
