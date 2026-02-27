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
// method-1
// O(n) time  , O(n) space  with 2 pass
class Solution {
public:
    unordered_map<int,int>mp;
    void inOrder(TreeNode* root)
    { 
        if(!root) return ;
        inOrder(root->left);
        mp[root->val]++;
        inOrder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        int maxFreq=0;
        for(auto  it =mp.begin();it!=mp.end();it++)
        {
            maxFreq=max(maxFreq,it->second);
        }
        vector<int>vec;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second== maxFreq) vec.push_back(it->first);
        }
        return vec;
    }
};
// methhod - 2
// O(n) time and space with 1 pass
class Solution {
public:
    unordered_map<int,int>mp;
    void inOrder(TreeNode* root)
    { 
        if(!root) return ;
        inOrder(root->left);
        mp[root->val]++;
        inOrder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        int maxFreq=0;
        vector<int>result;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second > maxFreq) 
            {
                result={};
                result.push_back(it->first);
                maxFreq=it->second;
            }
            else if(it->second ==maxFreq)
            {
                result.push_back(it->first);
            }
        }
        
        return result;
    }
};
// method -3

// O(n) time , O(1) space
class Solution {
public:
    int currNum=0;
    int currFreq=0;
    int maxFreq=0;
    vector<int>result;
    void dfs(TreeNode* root)
    { 
        if(!root) return ;
        dfs(root->left);
        if(root->val ==currNum) 
        {
            currFreq++;
        }
        else 
        {
            currFreq=1;
            currNum=root->val;
        }


        if( currFreq> maxFreq) 
        {
            result={};
            maxFreq=currFreq;
        }
        if(currFreq == maxFreq)
        {
            result.push_back(currNum);
        }
        dfs(root->right);

    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return result;
    }
};
