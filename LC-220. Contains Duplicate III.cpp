// method -1 think a smart solution  with brute force
class Solution {
public:
bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i]) != mp.end() &&  abs(mp[nums[i]] - i) <=k ) return true;

             mp[nums[i]]=i;
        }
        return false;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if(valueDiff==0) return containsNearbyDuplicate(nums,indexDiff);
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int ele=nums[i];
            // check in left
            for(int j=i-1;j>=0 && abs(j-i) <= indexDiff ;j--)
            {
                if(abs(ele-nums[j]) <= valueDiff) return true;
            }

        }

        return false;
        
    }
};

// method -2 using ordered set and sliding wondow
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
        set<long long> s;
        s.insert(nums[0]);
        int j=0;
        for(int i=1;i<nums.size();i++)
        {
            long long num=nums[i];

            auto it=s.lower_bound(num-valueDiff);

            if(it!=s.end() && *it<= num+valueDiff)
                return true;

            s.insert(num);

            if(abs(j-i)>=indexDiff)
            {
                s.erase(nums[j]);
                j++;
            }
        }

        return false;
    }
};
