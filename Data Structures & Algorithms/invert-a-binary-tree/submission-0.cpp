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
    TreeNode* invertTree(TreeNode* root) {
        stack<long long>st;
        TreeNode * t=root;
        long long i;
        while(t||!st.empty()){
            if(t){
                st.push((long long)t);
                t=t->left;
            }
            else{
                i=st.top();
                st.pop();
                if(i>0){
                    st.push(-i);
                    t=((TreeNode*) i)->right;
                }
                else{
                    t=((TreeNode*) -i);
                    TreeNode* s=t->left;
                    t->left=t->right;
                    t->right=s;
                    t=nullptr;
                }
            }      
        }
        return root; 
    }
};
