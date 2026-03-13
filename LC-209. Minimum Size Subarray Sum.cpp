class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        long long currWindowSum=0;
        int result=n+1;
        while(j<n)
        {
            currWindowSum+=nums[j];
            if(currWindowSum >=target)
            {
                while(currWindowSum >=target && i<n)
                {
                    result=min(result,j-i+1);
                    currWindowSum -=nums[i];
                    i++;
                }
            }
            
            j++;
        }
        return result == n+1 ? 0: result;
    }
};
