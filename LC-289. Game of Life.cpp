class Solution {
public:
   vector<vector<int>>directions{{-1,-1},{-1,0},{-1,1},
                            {0,-1},{0,1},
                           {1,-1},{1,0},{1,1}};
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>result(m,vector<int>(n));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int liveCell=0;
                for(auto &dir:directions)
                {
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];

                    if(new_i >=0 && new_i< m && new_j >=0 && new_j<n)
                    {
                        if(board[new_i][new_j]==1) liveCell++;
                    }
                }
                if(board[i][j] ==0)
                {
                    if(liveCell==3) result[i][j]=1;
                }
                else{
                    if(liveCell==3 || liveCell==2 ) result[i][j]=1;
                    else result[i][j]=0;
                }
            }
        }

        board= result;
    }
};

//method -2 in-place
class Solution {
public:
   vector<vector<int>>directions{{-1,-1},{-1,0},{-1,1},
                            {0,-1},{0,1},
                           {1,-1},{1,0},{1,1}};
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int liveCell=0;
                for(auto &dir:directions)
                {
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];

                    if(new_i >=0 && new_i< m && new_j >=0 && new_j<n)
                    {
                        if(abs(board[new_i][new_j] ) ==1 ) liveCell++;
                    }
                }
                if(board[i][j] ==0)
                {
                    if(liveCell==3) board[i][j]=2; // make it live for resultant 
                }
                else{
                    if(liveCell==3 || liveCell==2 ) board[i][j]=1;
                    else board[i][j]=-1; // dead cell marks as -1 for calculating the livecells
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]== 1 || board[i][j]==2) board[i][j]=1; 
                else board[i][j]=0; 
            }
        }

    }
};
