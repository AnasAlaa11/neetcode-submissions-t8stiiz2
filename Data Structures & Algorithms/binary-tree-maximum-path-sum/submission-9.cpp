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
    int maximum=INT_MIN;
    int getbranch(TreeNode* root){
        if(root==nullptr) return 0;
        int x=max(0,getbranch(root->left));
        int y=max(0,getbranch(root->right));
        maximum=max(maximum,x+y+root->val);
        return root->val+max(x,y);
    }
    int maxPathSum(TreeNode* root) {
        getbranch(root);
        return maximum;
    }
};
