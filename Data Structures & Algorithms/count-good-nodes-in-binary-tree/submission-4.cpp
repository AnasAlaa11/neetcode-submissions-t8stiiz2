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
    int dfs(TreeNode* t,int maxVal){
        int res;
        if(t==nullptr) return 0;
        if(t->val>=maxVal) res=1;
        else res=0;
        maxVal=max(t->val,maxVal);
        res+=dfs(t->left,maxVal);
        res+=dfs(t->right,maxVal);
        return res;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};
