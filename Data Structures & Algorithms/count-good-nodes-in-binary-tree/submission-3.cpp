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
    int goodNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int res=0;
        stack<long long> st;
        stack<pair<TreeNode*,int>> check;
        TreeNode* t=root;
        long long temp;
        while(!st.empty()||t!=nullptr){
            if(t!=nullptr){
                st.push((long long)t);
                if(check.empty()||check.top().second<=t->val){
                    check.push({t,t->val});
                    res++;
                }
                t=t->left;
            }
            else{
                temp=st.top();
                st.pop();
                if(temp>0){
                    st.push(-temp);
                    t=((TreeNode*)temp)->right;
                }
                else{
                    if(!check.empty()&&(TreeNode*)(-temp)==check.top().first){
                        check.pop();
                    }
                    t=nullptr;    
                }
            }
        }
       return res; 
    }
};
