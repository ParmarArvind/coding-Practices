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
    map<TreeNode*,pair<int,int> > mp;
    int findHeight(TreeNode* root)
    {
        if(!root) return 0;

        int left=0;
        if(root->left) left=1+findHeight(root->left);
        int right=0;
        if(root->right) right=1+findHeight(root->right);
        mp[root]={left,right};
        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
         findHeight(root);
         for(auto &root:mp)
         {
            if(abs(root.second.first - root.second.second)>1) return false;
        }
        return true;
        
    }
};

// without extra space
class Solution {
public:
    
    int findHeight(TreeNode* root)
    {
        if(!root) return 0;

        int left = findHeight(root->left);
        if(left == -1) return -1;

        int right = findHeight(root->right);
        if(right == -1) return -1;

        if(abs(left - right) > 1)
            return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return findHeight(root) != -1;
    }
};
