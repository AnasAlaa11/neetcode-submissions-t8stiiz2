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
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        bool check=true;
        check = isValidBST(root->left);
        if(st.empty()||root->val>st.top())
            st.push(root->val);
        else return false;
        if(check)
            check = isValidBST(root->right);
        return check;
    }
};