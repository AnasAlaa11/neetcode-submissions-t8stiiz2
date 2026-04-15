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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int>> res;
        queue <TreeNode*> q;
        TreeNode* t=root;
        vector <int> temp;
        temp.emplace_back(t->val);
        res.emplace_back(temp);
        q.push(t);
        while (!q.empty()){
            vector <int> te;
            int current=q.size();
            for(int i=0;i<current;i++){
                t=q.front();
                q.pop();
                if(t->left){
                    q.push(t->left);
                    te.emplace_back(t->left->val);
                }
                if(t->right){
                    q.push(t->right);
                    te.emplace_back(t->right->val);
                }
            }
            if(!te.empty())
            res.emplace_back(te);
        }
        return res;
    }
};
