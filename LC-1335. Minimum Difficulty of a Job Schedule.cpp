class Solution {
public:
    int dp[301][11];
    int solve(vector<int>& jd,int n,int idx,int remiDay)
    {
        // base case i.e.
        // If you have only 1 day, then you will do all the remaining jobs
        // and select the max difficulty as the answer
        if(remiDay==1)
        {
            int maxDiff=jd[idx];
            for(int i=idx;i<n;i++)
            {
                maxDiff=max(maxDiff,jd[i]);
            }
            return maxDiff;
        }

         // Try one by one with all possibilities
        /*
            Take 1 job in one day
            Take 2 jobs in one day
            Take 3 jobs in one day
            ...
            and so on
            
            Then find the optimal one among all the results
        */

        if(dp[idx][remiDay] !=-1) return dp[idx][remiDay];
        int maxDiff=jd[idx];
        int finalResult=INT_MAX;
        for(int i=idx;i<=n-remiDay ;i++)
        {
            maxDiff=max(maxDiff, jd[i]);
            int result= maxDiff +solve(jd,n,i+1,remiDay-1);
            finalResult=min(result,finalResult);
        }

        return dp[idx][remiDay] =finalResult;

    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d) return -1;
        memset(dp,-1,sizeof(dp));
        return solve(jobDifficulty,n,0,d);
    }
};
