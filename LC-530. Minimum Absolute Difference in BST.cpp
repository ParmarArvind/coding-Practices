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
// O(n) time and O(n) space
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
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        int result=INT_MAX;
        for(int i=1;i<vec.size();i++)
        {
            result =min(result ,vec[i]-vec[i-1]);
        }
        return result;
    }
};


// O(n) time , O(1) space
class Solution {
public:
    int result;
    void inOrder(TreeNode* root,TreeNode* &prev)
    {
        if(root==NULL) return ;
        inOrder(root->left,prev);
        if(prev !=NULL)
        {
            result=min(result, root->val - prev->val);
        }
        
        prev=root;
        
        inOrder(root->right,prev);
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev=NULL;
        result=INT_MAX;
        inOrder(root,prev);
         
        return result;
    }
};
