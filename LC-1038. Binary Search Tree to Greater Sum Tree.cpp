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
// metod -1 O(n*logn) time , O(n) space
class Solution {
public:
    vector<int>suffix;
    vector<int> vec;
    int n;
    void inOrder(TreeNode* root)
    {
        if(!root) return;
        inOrder(root->left);
        vec.push_back(root->val);
        inOrder(root->right);
    }

    void inOrderUpdate(TreeNode* root)
    {
        if(!root) return;
        inOrderUpdate(root->left);
        int start=0;
        int end=n-1;
        int mid;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(vec[mid]==root->val)
            {
                break;
            }
            else if(vec[mid] < root->val) start=mid+1;
            else end=mid-1;
        }
        root->val=suffix[mid];
        inOrderUpdate(root->right);
    }

    TreeNode* bstToGst(TreeNode* root) {
        inOrder(root);
         n=vec.size();
        suffix.resize(n);
        suffix[n-1]=vec[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=suffix[i+1]+vec[i];
        }


        inOrderUpdate(root);

        return root;
        
    }
};

// method-2  optimal  O(n) time ,  O(1) space
class Solution {
public:
    int sum=0;
    void inOrder(TreeNode* root) {
        if (!root)
            return;
         
        inOrder(root->right);

        sum +=root->val;
        root->val=sum;

        inOrder(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        inOrder(root);
        return root;
    }
};
