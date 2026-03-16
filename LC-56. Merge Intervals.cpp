class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return intervals;

        vector<vector<int>> ans;

        // Sort intervals by start time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int i = 0;
        while (i < n) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            int j = i + 1;
            while (j < n && end >= intervals[j][0]) {
                end = max(end, intervals[j][1]);
                j++;
            }

            ans.push_back({start, end});
            i = j;  // move to the next non-overlapping interval
        }

        return ans;
    }
};
