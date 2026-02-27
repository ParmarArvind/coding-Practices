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
// method one using O(n) space && O(n) time
class Solution {
public:
    vector<int>vec;
    void inOrder(TreeNode* root)
    {
        if(root==NULL) return ;
        inOrder(root->left);
        vec.push_back(root->val);
        inOrder(root->right);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        inOrder(root);
        int result=0;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]>=low && vec[i]<=high) result+=vec[i];
        }
        return result;
    }
};

=// method 2  O(n) time
class Solution {
public:
    int result;
    void inOrder(TreeNode* root,int low, int high)
    {
        if(root==NULL) return ;
        inOrder(root->left,low,high);
        if(root->val >=low && root->val <=high ) result+=root->val;
        inOrder(root->right,low,high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
       
        result=0;
        inOrder(root,low,high);
        return result;
    }
};

// method -3 improved using BST property

class Solution {
public:
    int result;
    void inOrder(TreeNode* root,int low, int high)
    {
        if(root==NULL) return ;
        if(root->val >= low) inOrder(root->left,low,high);

        if(root->val >=low && root->val <=high ) result+=root->val;

        if(root->val <= high) inOrder(root->right,low,high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
       
        result=0;
        inOrder(root,low,high);
        return result;
    }
};
