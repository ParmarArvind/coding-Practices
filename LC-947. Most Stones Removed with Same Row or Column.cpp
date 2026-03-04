//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    void dfs(vector<vector<int>>&stones ,vector<bool>&visited,int idx)
    {
        visited[idx]=true;

        for(int i=0;i<stones.size();i++)
        {
            int row=stones[idx][0];
            int col=stones[idx][1];

            if(!visited[i]  && (stones[i][0] == row || stones[i][1]==col))
            {
                dfs(stones,visited,i);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool>visited(n,false);
        int group=0;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(stones,visited,i);
                group++;
            }
        }

        return n-group;
    }
};
