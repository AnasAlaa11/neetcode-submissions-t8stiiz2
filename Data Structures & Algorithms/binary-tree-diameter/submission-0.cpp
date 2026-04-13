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
    int height(TreeNode* t){
        int x,y;
        if(t==nullptr) return 0;
        x=height(t->left);
        y=height(t->right);
        if(x>y) return x+1;
        else return y+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        queue<TreeNode*>q;
        stack<TreeNode*>st;
        TreeNode * t;
        int m=0;
        q.push(root);
        while(!q.empty()){
            t=q.front();
            q.pop();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            int x=height(t->left);
            int y=height(t->right);
            int res=x+y;
            m=max(res,m);
        }
        return m;
    }
};
