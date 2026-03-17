
class Solution {
public:
    int dp[101][101];
    
    int solve(int m,int n,int row,int col)
    {
        if(row>=m || col >=n) return 0;
        
        if(row==m-1 && col==n-1) return 1;

        if(dp[row][col] !=-1 ) return dp[row][col];

        int right = solve(m, n, row, col + 1);
        int down  = solve(m, n, row + 1, col);

        return dp[row][col] = right + down;
    }
    int uniquePaths(int m,int n) {
        
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(m,n,0,0);
    }
};
