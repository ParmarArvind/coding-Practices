//method -1  O(n*logn) 
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        auto lambda=[](auto &a,auto &b)
        {
            return a[0]<b[0];
        };

        sort(intervals.begin(),intervals.end(),lambda);

         vector<vector<int>> ans;

        int i=0;
        int n=intervals.size();
        while(i<n)
        {
            int start=intervals[i][0];
            int end=intervals[i][1];

            int j=j+1;
            while(j<n && end>= intervals[j][0])
            {
                end= max(end,intervals[j][1]);
                j++;
            }
            ans.push_back({start,end});
            i=j;
        }
        return ans;
    }

};
//method -2  O(n*n) 
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int i = 0;
      
        while (i < intervals.size())
        {
            if( intervals[i][1] < newInterval[0]) i++;
            else if( intervals[i][0] > newInterval[1])
            {
                intervals.insert(intervals.begin()+i , newInterval);
                return intervals;
            }
            else{
                // merge them 
                newInterval[0]=min(newInterval[0],intervals[i][0] );
                newInterval[1]=max(newInterval[1] , intervals[i][1]);
                intervals.erase(intervals.begin()+i);
            }
        }

        intervals.push_back(newInterval);

        return intervals;
    }
};

// method -3 O(n);
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int i = 0;
        vector<vector<int>>result;
        int n=intervals.size();
        while (i < n)
        {
            if( intervals[i][1] < newInterval[0]) {
                result.push_back(intervals[i]);
            }
            else if( intervals[i][0] > newInterval[1])
            {
                break;
            }
            else{
                // merge them 
                newInterval[0]=min(newInterval[0],intervals[i][0] );
                newInterval[1]=max(newInterval[1] , intervals[i][1]);
            }
            i++;
        }

        result.push_back(newInterval);
        while(i<n) 
        {
             result.push_back(intervals[i]);
             i++;
        }

        return result;
    }
};
