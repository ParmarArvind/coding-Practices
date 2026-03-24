//method -1 recursion and memoization 
class Solution {
public:
    int n;
    int dp[2501][2501];
    int solve(int index,vector<int>& nums,int previous)
    {
        if(index>=n) return 0;

        if(previous !=-1 && dp[index][previous] != -1) return dp[index][previous];

        // take
        int take=0;
        if(previous == -1 || nums[previous] < nums[index] )
        {
            take=1+solve(index+1,nums,index);
        }
        
        // skip
        int skip=solve(index+1,nums,previous);

        if(previous != -1)
            return dp[index][previous]=max(take,skip) ;

        return  max(take,skip);
        
    }

    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();

        memset(dp,-1,sizeof(dp));

        return solve(0,nums,-1);
        
    }
};

//method -2 bottom up
class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);  // dp[i] = LIS ending at i (min length 1)
        int maxLIS = 1;        // track overall maximum

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // if nums[j] can precede arr[i], extend the subsequence
                if (arr[j] < arr[i]) {
                    dp[i]  = max(dp[i], dp[j] + 1);
                    maxLIS = max(maxLIS, dp[i]);
                }
            }
        }
        return maxLIS;
    }
};
