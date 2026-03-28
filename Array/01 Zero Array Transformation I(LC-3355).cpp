class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int> shift(n,0);

        for(int i=0;i<m;i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];
            shift[start]++;
            if(end+1<n) shift[end+1] -=1;
        }
        for(int i=1;i<n;i++){
            shift[i]=shift[i]+shift[i-1];
        }

        for(int i=0;i<n;i++){
            if(nums[i]>shift[i]) return false;
        }
        return true;

    }
};
