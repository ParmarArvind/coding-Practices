class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string> result;
        if(n==0) return result;
        if(n==1) 
        {
            result.push_back(to_string(nums[0]));
            return result;
        }
        
        int start=0;
        int end=-1;
        for(int i=1;i<n;i++)
        {
            long long diff=(long long)nums[i]- (long long)nums[i-1];
            if(diff ==1LL) end=i;
            else{
                string temp=to_string(nums[start]);
                
                if(end != -1) temp += "->" +to_string(nums[end]);
                start=i;
                end=-1;

                result.push_back(temp);
            }
        }
        string temp=to_string(nums[start]);
        if(end != -1) temp += "->" +to_string(nums[end]);
        result.push_back(temp);
        return result;
    }
};
