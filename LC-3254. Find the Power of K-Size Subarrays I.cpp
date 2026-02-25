// method 1 -> brute force O(n*k)
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> result(n-k+1);
        for(int i=0;i<n-k+1;i++)
        {
            bool flag=true;
            for(int j=i+1;j<i+k;j++)
            {
                if(nums[j] - nums[j-1] != 1)
                {
                    flag= false;
                    break;
                }
            }
            result[i]= flag ? nums[i+k-1]:-1;
        }
        return result;
    }
};


// method 2 -> sliding window  O(n)
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1) return nums;
        int n=nums.size();
        vector<int> result(n-k+1 ,-1);
        
        int count=1;
        // first slide
        for(int i=1;i<k;i++)
        {
            if(nums[i]-nums[i-1] ==1 ) 
            {
                count++;
            }  
            else count=1;
        }

        if(count==k) result[0]=nums[k-1];

        // next slides
        int i=1;
        int j=k;
        while(j<n)
        {
            if(nums[j]-nums[j-1] ==1) count++;
            else count=1;

            if(count>=k) result[i]=nums[j];
            i++;
            j++;
        }
        return result;
    }
};
