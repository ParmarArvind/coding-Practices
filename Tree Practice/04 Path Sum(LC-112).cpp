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
    bool check(TreeNode* root, int targetSum)
    {
        if(!root)
        {
            if(targetSum==0) return true;
            return false;
        }
        if(root->left && root->right)
        return check(root->left ,targetSum-root->val) ||check(root->right ,targetSum-root->val);
        else if(root->left)  return check(root->left ,targetSum-root->val);
        else return check(root->right ,targetSum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return check(root,targetSum);
    }
};
