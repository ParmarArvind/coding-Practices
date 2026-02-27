class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pair<int,int>> mp(n);
        for(int i=0;i<n;i++)
        {
            mp[i]={plantTime[i],growTime[i]};
        }

        auto lambda =[](pair<int,int> &a,pair<int,int> &b)
        {
            return a.second>b.second;
        };
        sort(mp.begin(),mp.end(),lambda);

        int result=0;
        int lastSeedDay=0;
        int maxDays=0;
        for(int i=0;i<n;i++)
        {
            int plantSeedTime=mp[i].first;
            int plantGrowTime=mp[i].second;

            lastSeedDay +=plantSeedTime;
           int currGrowTime= lastSeedDay + plantGrowTime;
            maxDays =max(maxDays,currGrowTime );
        }
        
        return maxDays;
    }
};
