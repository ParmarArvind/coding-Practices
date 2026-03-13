class Solution {
public:
    int dp[13][10001];
    int solve(int i, vector<int>& coins, int currAmount) {
       
        if (i == coins.size()) {
            if (currAmount == 0) 
                return 0;
            else return INT_MAX;
        }

        if (dp[i][currAmount] != -1) return dp[i][currAmount];
        // take
        int take =INT_MAX;
        if(currAmount-coins[i] >=0 ) 
        {
            int res=solve(i, coins, currAmount - coins[i]);
            if(res !=INT_MAX) take=1+res;
        }

        // skip
        int skip = solve(i + 1, coins, currAmount);
        
        return dp[i][currAmount] = min(take,skip);
    }
    

    int coinChange( vector<int>& coins,int amount) {
        memset(dp, -1, sizeof(dp));
        int result=solve(0, coins, amount) ;
        return result!=INT_MAX ?result:-1;
    }
};
