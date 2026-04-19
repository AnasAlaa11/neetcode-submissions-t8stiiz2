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
    void DFS(TreeNode* t, int k, int &count, int &res){
        if(t==nullptr) return;
        DFS(t->left,k,count,res);
        if(count==k){
            res=t->val;
           count++;
        }
        else count++;
        DFS(t->right,k,count,res);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=1;
        int res;
        DFS(root,k,count,res);
        return res;
    }
};
