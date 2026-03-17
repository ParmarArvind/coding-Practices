
class Solution {
public:
    int dp[201][201];
    int n;
    int m;
    int solve(vector<vector<int>>& grid,int row,int col)
    {
        if(row>=m || col >=n) return INT_MAX;
        
        if(row==m-1 && col==n-1) return grid[row][col];

        if(dp[row][col] !=-1 ) return dp[row][col];

        int sameCol=solve(grid,row,col+1);
        int nextCol=solve(grid,row+1,col);

        return dp[row][col]=grid[row][col] + min(sameCol,nextCol);
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        for(int i = 0; i < 201; i++) {
            for(int j = 0; j < 201; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(grid,0,0);
    }
};
