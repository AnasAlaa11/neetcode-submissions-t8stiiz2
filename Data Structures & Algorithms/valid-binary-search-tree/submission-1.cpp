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
    stack<int> st;
    bool validate(TreeNode*t,TreeNode* & pre){
        if(t==nullptr) return true;
        bool check=true;
        check = validate (t->left,pre);
        if(pre!=nullptr&&t->val<=pre->val)
            return false;
        else pre= t;
        if(check)
            check = validate(t->right,pre);
        return check;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* pre=nullptr;
        return validate(root,pre);
    }
};