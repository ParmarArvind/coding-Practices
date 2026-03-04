class Solution {
public:
    vector<vector<int>>direction {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();

        queue<pair<int,int>> que;
        que.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int steps=0;

        // write classical BFS
        while(!que.empty())
        {
            int size=que.size();

            while(size--)
            {
                pair<int ,int> p=que.front();
                que.pop();
                int i=p.first;
                int j=p.second;
                //boundry per pahuch gya
                if(p != make_pair(entrance[0],entrance[1]) && ( i==0 || i==m-1  || j==0 || j==n-1) )
                {
                    return steps;
                }

                // explore nighbour
                for(auto &dir : direction)
                {
                    int new_i= i+dir[0];
                    int new_j= j+dir[1];

                    if(new_i >= 0 && new_i < m  && new_j >= 0  && new_j < n &&  maze[new_i][new_j] !='+')
                    {
                        que.push( make_pair(new_i,new_j) );
                        maze[new_i][new_j]='+'; //mark it visited
                    }
                }
                
            }
            steps++;
        }

        return -1; //not exits
    }
};
