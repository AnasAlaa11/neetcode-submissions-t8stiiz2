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
    bool flag = true;
    int height(TreeNode * t){
        if(t==nullptr) return 0;
        int x=height(t->left);
        int y=height(t->right);
        if(x>y+1||y>x+1) flag=false;
        if(x>y) return x+1;
        else return y+1;
    }
    bool isBalanced(TreeNode* root){
        int x=height(root);
        return flag;

    }
};
