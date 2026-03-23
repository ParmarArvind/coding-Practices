class Solution {
public:
    vector<int> parent;
    vector<int>rank;

    int find(int x)
    {
        if(parent[x]== x) return x;

        return parent[x]=find(parent[x]);
    }
    void Union(int x, int y)
    {
        int x_parent=find(x);
        int y_parent=find(y);
        if(x_parent==y_parent) return;

        // jdiki rank jayada hai use parent bana do
        if(rank[x_parent] >rank[y_parent]) 
        {
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent] <rank[y_parent]) 
        {
            parent[x_parent]=y_parent;
        }
        else{
            // dame rank hai toh kisi ko bhi parent bana do or uski rank +1 kar do 
             parent[x_parent]=y_parent;
             rank[y_parent]++;
        }
    } 

    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size()<n-1) return -1;
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
        int component=n;

        for(int i=0;i<connections.size();i++)
        {
            int x=connections[i][0];
            int y=connections[i][1];

            int x_parent=find(x);
            int y_parent=find(y);
            if(x_parent!=y_parent)
            {
                Union(x_parent,y_parent);
                component--;
            }
        }
       return component-1;
        
    }
};
