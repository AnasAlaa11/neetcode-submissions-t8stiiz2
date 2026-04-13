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
    int maxDepth(TreeNode* root) {
        TreeNode * t=root;
        int level =0;
        if(t==nullptr) return 0;
        queue<TreeNode*> q;
        q.push(t);
        while(!q.empty()){
            int currentLevelSize = q.size();
            for(int i=0;i<currentLevelSize;i++){
                t=q.front();
                q.pop();
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            level++;
        }
        return level;
    }
};
