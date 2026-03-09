//using dfs
class Solution {
public:
// using dfs
    bool dfs(unordered_map<int,vector<int>>& adj,vector<bool> &visited,vector<bool>& inRecursion,int u)
    {
        visited[u]=true;
        inRecursion[u]=true;

        for(int v:adj[u])
        {
            if(inRecursion[v] ==true) return true;
            if(!visited[v] && dfs(adj,visited,inRecursion,v))
                return true;
            
        }
        inRecursion[u]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // make graph .
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];

            adj[u].push_back(v);
        }

        vector<bool> visited(numCourses,0);
        vector<bool> inRecursion(numCourses,0);

        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i] && dfs(adj,visited,inRecursion,i) ) return false;
        }

        
        return true;
        
    }
};

// using bfs
class Solution {
public:

    bool topologocalCheck(unordered_map<int,vector<int>>& adj,vector<int>&indegree,int n)
    {
        int count=0;
        //2. indegree 0 walo ko push kar do
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0) 
            {
                q.push(i);
                count++;
            }
            
        }
        // simple bfs
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int v:adj[u])
            {
                indegree[v]--;

                if(indegree[v]==0) 
                {
                    q.push(v);
                    count++;
                }
            }
        }
         
         return count==n;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // make graph and find indegrees.
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            adj[u].push_back(v);

            indegree[v]++;
        }
        

        return topologocalCheck(adj,indegree,numCourses);
        

    }
};
