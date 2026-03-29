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
    map< pair<TreeNode*,bool> ,int>dp;
    int solve(TreeNode* root,bool isParentThifed)
    {
        if(!root) return 0;

        if(dp.count({root,isParentThifed})) return dp[{root,isParentThifed}];

        int take=0;
        if(isParentThifed) take=solve(root->left,false)+solve(root->right,false);
        else take=root->val + solve(root->left,true)+solve(root->right,true);

        int skip=solve(root->left,false)+solve(root->right,false);

        return dp[{root,isParentThifed}]=max(skip,take);
    }
    int rob(TreeNode* root) {
        
        return solve(root,false);
        
    }
};
