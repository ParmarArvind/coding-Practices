// method -1 wihtout dp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> solve(int start,int end)
    {
        if(start>end) return {NULL};
        if(start==end)
        {
            TreeNode* root=new TreeNode(start);
            return {root};
        }

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
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
        
    }
};


///method -2 with dp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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

        return mp[{start,end}]=result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
        
    }
};
