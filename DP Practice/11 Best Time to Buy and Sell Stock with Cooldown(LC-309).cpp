class Solution {
public:
int n;
int t[5001][2];
    int solve(vector<int>& prices ,int i,int prevOp)
    {
        if(i>=n) {
            if(prevOp==0) return 0;
            return INT_MIN;
        }
        if(prevOp !=-1 && t[i][prevOp] !=-1) return t[i][prevOp];
        int take=INT_MIN;
        int skip=INT_MIN;
        if(prevOp==-1 || prevOp==0)
        {
            take = - prices[i] ;
            int tempTake= solve(prices,i+1,1);
            if(tempTake == INT_MIN) take=INT_MIN;
            else take += tempTake;
            
           int tempSkip= solve(prices,i+1,prevOp);
            if(tempSkip == INT_MIN) skip=INT_MIN;
            else skip= tempSkip;
        }
        else if(prevOp ==1)
        {
            // (buy) is not possible sell it now
            take = prices[i] ;
            int tempTake= solve(prices,i+2,0);
            if(tempTake == INT_MIN) take=INT_MIN;
            else take += tempTake;

           int tempSkip= solve(prices,i+1,prevOp);
            if(tempSkip == INT_MIN) skip=INT_MIN;
            else skip= tempSkip;
        }
        if(prevOp==-1) return max(take,skip);
        return t[i][prevOp]=max(take,skip);
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        memset(t,-1,sizeof(t));
        int result=solve(prices,0,-1);
        return result==INT_MIN || result<0  ? 0: result;
    }
};
