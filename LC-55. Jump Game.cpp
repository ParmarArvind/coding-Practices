// method-1 top down
class Solution {
public:
    bool solve(vector<int>& nums, int idx, vector<int>& dp)
    {
        if(idx >= nums.size()-1) return true;

        if(nums[idx] == 0) return false;

        if(dp[idx] != -1) return dp[idx];

        if(nums[idx] >= nums.size()-1-idx) 
            return dp[idx] = true;

        for(int i = 1; i <= nums[idx]; i++)
        {
            if(solve(nums, idx + i, dp) == true)
                return dp[idx] = true;
        }

        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, 0, dp);
    }
};

// method -2 bottom up O(n^2)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> t(n,false);
        t[0]=true;
        //t[i] ==true means mai t[i] tak pahuch sakta hu
        // t[i]==flase means mai t[i] tak nhi pahuch sakta

        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0 ;j--)
            {
                if(t[j]==true && j+nums[j]>=i)
                {
                    t[i]=true;
                    break;
                }
            }
        }

        return t[n-1];
    }
};

// method -3  O(n)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        
        int maxReachable=0;

        for(int i=0;i<n;i++)
        {
            if(i>maxReachable) return false;
            maxReachable=max(maxReachable,nums[i]+i);
        }

        return true;
    }
};
