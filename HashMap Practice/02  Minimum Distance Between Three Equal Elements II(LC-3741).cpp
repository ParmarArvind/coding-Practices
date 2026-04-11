// TLE O(n^3)
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int x=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(nums[i]==nums[j] && nums[j]==nums[k]) x=min(x, 2*(k-i ) );
                }
            }
        }
        return x==INT_MAX ? -1 :x;
        
    }
};

//O(n)
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>idx;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            idx[nums[i]].push_back(i);
        }

        int result=INT_MAX;

        for(auto &num:idx)
        {
            vector<int>&vec=num.second;
            if(vec.size()<3) continue;
           
            for(int i=0;i<vec.size()-2;i++)
            {
                result=min(result , 2*( vec[i+2] - vec[i] ));
            }
        }

        return result==INT_MAX ? -1 :result;
    }
};
