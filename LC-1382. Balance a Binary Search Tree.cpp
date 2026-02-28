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
    vector<int> vec;
    void inOrder(TreeNode* root)
    {
        if(!root) return;
        inOrder(root->left);
        vec.push_back(root->val);
        inOrder(root->right);
    }

    TreeNode* solve(int left,int right) {
        if(left>right) return NULL;

        TreeNode* root=new TreeNode();
        int mid=left+(right-left)/2;
        root->val=vec[mid];
        root->left=solve(left,mid-1);
        root->right=solve(mid+1,right);
        return root;
    }


    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);

        return solve(0,vec.size()-1);
    }
};
