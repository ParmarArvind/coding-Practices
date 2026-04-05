// method -1 recursoion (TLE)
class Solution {
public:
    typedef long long ll;
    int n;
    pair<ll, ll > solve(vector<int>& nums ,int i,ll prevSpecial, ll op ){ //max Special ele ,min operations
        if(i >= n-1) return {prevSpecial,op};


        pair<ll,ll> take={0L,0L};

        if(nums[i] > nums[i-1] && nums[i]>nums[i+1]) take = solve(nums,i+2, prevSpecial+1 , op);
        else {
            ll requiredOp = (ll)(max(nums[i-1],nums[i+1]) -nums[i] +1);
            take = solve(nums, i+2,  prevSpecial+1 , op + requiredOp);
        }

        pair<ll,ll> skip = solve(nums,i+1, prevSpecial , op);
        
        return  take.first==skip.first ? (take.second<=skip.second ? take : skip ) : take.first> skip.first  ? take : skip;
    }
    ll minIncrease(vector<int>& nums) {
        n=nums.size();
       
        return solve(nums,1,0L,0L).second;
        
    }
};

// method -2 (recursion and memization ) O(logn*n) TLE bcoz of map  
class Solution {
public:
    typedef long long ll;
    int n;
    map<int,pair<ll,ll>>mp;
    pair<ll, ll > solve(vector<int>& nums ,int i){ //max Special ele ,min operations
        if(i >= n-1) return {0L,0L};

        if(mp.find(i) != mp.end()) return mp[i];

        pair<ll,ll> take={0L,0L};
        if(nums[i] > nums[i-1] && nums[i]>nums[i+1]) {
            take = solve(nums,i+2);
            take.first += 1;
        }
        else {
            ll requiredOp = (ll)(max(nums[i-1],nums[i+1]) -nums[i] +1);
            
            take = solve(nums, i+2);
           
            take.first += 1;
            take.second += requiredOp;
        }

        pair<ll,ll> skip = solve(nums,i+1);
        
        return  mp[i]=take.first==skip.first ? (take.second<=skip.second ? take : skip ) : take.first> skip.first  ? take : skip;
    }
    ll minIncrease(vector<int>& nums) {
        n=nums.size();
        mp.clear();
        return solve(nums,1).second;
    }
};


// method -3 (recursion and memization ) O(n) use of vector instead of map
class Solution {
public:
    typedef long long ll;

    int n;

    vector<pair<ll,ll>> dp;
    vector<bool> visited;

    pair<ll,ll> solve(vector<int>& nums, int i){

        if(i >= n-1) return {0,0};

        if(visited[i]) return dp[i];

        ll reuiredOp =max(0LL,  (ll)max(nums[i-1], nums[i+1]) + 1 - nums[i]);

        // take current index
        pair<ll,ll> take = solve(nums, i+2);

        take.first += 1;
        take.second += reuiredOp;

        // skip current index
        pair<ll,ll> skip = solve(nums, i+1);

        // choose better option
        if(take.first == skip.first)
            dp[i] = take.second <= skip.second ? take : skip;
        else
            dp[i] =take.first > skip.first ?  take : skip;

        visited[i] = true;

        return dp[i];
    }

    long long minIncrease(vector<int>& nums) {

        n = nums.size();

        if(n < 3) return 0;

        dp.resize(n);
        visited.resize(n,false);

        return solve(nums,1).second;
    }
};
