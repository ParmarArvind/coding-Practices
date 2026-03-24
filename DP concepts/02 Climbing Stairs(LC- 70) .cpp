// method 3 constant space
class Solution {
public:
    int climbStairs(int n) {
        if(n<=3) return n;

        int a=1;
        int b=2;
        int c;
        for(int i=3;i<=n;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }

        return c;
        
    }
};

// method 2 bottom up
class Solution {
public:
    int climbStairs(int n) {
        if(n<=3) return n;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;

        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n];
        
    }
};

// method 1 recusrion + memotization
class Solution {
public:

    int solve(int n, vector<int>& dp)
    {
        if(n<=3) return n;

        if(dp[n] !=-1) return dp[n];

        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int > dp(n+1,-1);

        return solve(n,dp);
    }
};
