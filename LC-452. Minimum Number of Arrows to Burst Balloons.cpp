class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>result(m - k + 1 , vector<int>(n - k + 1 ));

        for(int i=0;i<=m-k;i++)
        {
            for(int j=0;j<=n-k;j++)
            {
                // make k*k matrix
                set<int>st;
                for(int r=i;r<=i+k-1; r++)
                {
                    for(int c=j;c<=j+k-1;c++)
                    {
                        st.insert(grid[r][c]);
                    }
                }
                if(st.size() ==1) 
                {
                    result[i][j]=0;
                    continue;
                }
                int minDiff=INT_MAX;
                auto prev=st.begin();
                auto curr=next(prev);

                while(curr != st.end())
                {
                    minDiff= min(minDiff, *curr -*prev);
                    prev=curr;
                    curr++;
                }
                result[i][j]=minDiff;
            }
        }
        return result;
    }
};
