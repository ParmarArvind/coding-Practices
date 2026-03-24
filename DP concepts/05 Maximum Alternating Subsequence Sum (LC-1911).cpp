//method -1 recursion and memoization
class Solution {
public:
    int n;
    typedef long long ll;

    ll t[100001][2];// two value change first index, second flag;

    ll solve(int index,vector<int>& nums, bool isEven)
    {
        if(index>=n)
        {
            return 0;
        }
        if(t[index][isEven] !=-1) return t[index][isEven];
        int value=nums[index];

        // skip
        ll skip=solve(index+1,nums,isEven);

        // check the index and take its value in result
        if(isEven==false) value = -value;
        ll take=value + solve(index+1,nums,!isEven);

        return t[index][isEven]=max(skip, take);

    }
    ll maxAlternatingSum(vector<int>& nums) {
        n= nums.size();
        memset(t,-1,sizeof(t));

        return solve(0,nums,true);
        
    }
};

// method 2 bottom up
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();

        vector < vector<long > > t(n+1,vector<long>(2,0));
        for(int i=1;i<n+1;i++)
        {
            t[i][0]=max( t[i-1][1]-nums[i-1], t[i-1][0]);

            t[i][1]=max(nums[i-1]+t[i-1][0],t[i-1][1]);

        }
        
        return max(t[n][0],t[n][1]);
    }
};
