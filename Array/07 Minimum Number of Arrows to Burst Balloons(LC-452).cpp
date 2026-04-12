class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int result=1;
        sort(points.begin(),points.end());
        vector<int>interval=points[0];

        int n=points.size();
        for(int i=1;i<n;i++)
        {
            int start=points[i][0];
            int end=points[i][1];

            if(interval[1]>= start)
            {
                interval[0]= max(start,interval[0]);
                interval[1]=min(interval[1],end);
            }
            else  
            {
                result++;
                interval=points[i];
            }
        }

        return result;
        
    }
};
