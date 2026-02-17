class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n = nums.size();
       
        for(int v=0; v<n-1; v=v+1){
            for(int u=v+1; u<n; u=u+1){
                int sum = nums[v]+nums[u];
                if(sum == target) return{v,u};
            }
        }

       return{-1,-1};
    }
};
