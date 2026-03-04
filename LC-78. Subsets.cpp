//Approach-1
//T.C : O(2^n)
//S.C :  O(2^n*length of each subset) to store each subset
//       The recursion stack space complexity is O(N) , the maximum depth of the recursion is N, where N is the length of the input array.

class Solution {
public:
    vector<vector<int>> result;
    int n;
    void solve(int i,vector<int>& nums,vector<int>& temp)
    {
        if(i==n)
        {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(i+1,nums,temp);

        temp.pop_back();
        solve(i+1,nums,temp);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<int>temp;
        solve(0,nums,temp);

        return result;
    }
};
