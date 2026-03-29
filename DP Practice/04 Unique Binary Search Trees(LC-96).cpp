// method -1 use of previous approach (TLE)
class Solution {
public:
    map<pair<int,int>,vector<TreeNode*>>mp;
    vector<TreeNode*> solve(int start,int end)
    {
        if(start>end) return mp[{start,end}]= {NULL};
        if(start==end)
        {
            TreeNode* root=new TreeNode(start);
            return mp[{start,end}] ={root};
        }

        if(mp.count({start,end})) return mp[{start,end}];

        vector<TreeNode*>result;
        // make each node as root one by one fromt start to end
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*>leftBSTs=solve(start,i-1);
            vector<TreeNode*>rightBSTs=solve(i+1,end);

            // connect all left BST to right BST
            for(auto &leftRoot:leftBSTs)
            {
                for(auto &rightRoot:rightBSTs)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=leftRoot;
                    root->right=rightRoot;

                    result.push_back(root);
                }
            }
        }
        return result;
    }

    int numTrees(int n) {
    
       vector<TreeNode*> result=solve(1,n);

       return result.size();
    }
};

// method -2 recursiion
class Solution {
public:
    int solve(int n)
    {
        if(n<=1) return 1;

        int ans=0;
        for (int i = 1; i <= n; i++) {
            ans += solve(i - 1) * solve(n - i);
        }
        return ans;
    }
    int numTrees(int n) {
        return solve(n);
    }
};

//method -3 recursion ane memoizataion
class Solution {
public:
    int t[20];
    int solve(int n)
    {
        if(n<=1) return 1;
        if(t[n]!=-1) return t[n];

        int ans=0;
        for (int i = 1; i <= n; i++) {
            ans += solve(i - 1) * solve(n - i);
        }
        return t[n]=ans;
    }
    int numTrees(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};

