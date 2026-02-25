class Solution {
public: 
    int removeDuplicates(vector<int>& nums) {
        int max = INT_MIN;
        int prev = -1;
        int n = nums.size();

        // Mark extra duplicates
        for(int i = 0; i < n; i++)
        {
            if(prev == -1) 
                prev = i;
            else if(nums[prev] == nums[i])
            {
                if(i - prev > 1)
                {
                    nums[i] = max;
                }
            }
            else 
                prev = i;
        }

        int i = 0;
        int j = 0;

        // Shift non-max elements forward
        while(j < n)
        {
            if(nums[i] != max)
            {
                i++;
                j++;
            }
            else
            {
                while(j < n && nums[j] == max) 
                    j++;

                if(j >= n) break;

                nums[i] = nums[j];
                nums[j] = max;
                i++;
                j = i;
            }
        }

        // Count valid elements
        for(int k = 0; k < n; k++)
        {
            if(nums[k] == max) 
                return k;
        }

        return n;
    }
};
