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
    int max_diameter=0;
    int height(TreeNode* t){
        int x,y;
        if(t==nullptr) return 0;
        x=height(t->left);
        y=height(t->right);
        max_diameter=max(max_diameter,x+y);
        if(x>y) return x+1;
        else return y+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return max_diameter;
    }
};
