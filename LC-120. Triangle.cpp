class Solution {
public:
    int dp[201][201];
    int n;
    int solve(vector<vector<int>>& triangle,int row,int col)
    {
        if(row>=n || col >=n) return 0;
        if(dp[row][col] !=INT_MAX ) return dp[row][col];
        int sameCol=triangle[row][col] +solve(triangle,row+1,col);
        int nextCol=triangle[row][col] +solve(triangle,row+1,col+1);

        return dp[row][col]=min(sameCol,nextCol);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        for(int i = 0; i < 201; i++) {
            for(int j = 0; j < 201; j++) {
                dp[i][j] = INT_MAX;
            }
        }
        return solve(triangle,0,0);
    }
};
