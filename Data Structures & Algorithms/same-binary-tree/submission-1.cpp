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
    bool isSameTree(TreeNode* p, TreeNode* q) {
       stack<TreeNode*> st1;
       stack<TreeNode*> st2;
       TreeNode * t1=p;
       TreeNode * t2=q;
       while((!st1.empty()||t1!=nullptr)||(!st2.empty()||t2!=nullptr)){
            if((t1!=nullptr&&t2==nullptr)||(t1==nullptr&&t2!=nullptr)) return false;
            if(t1&&t2){
                st1.push(t1);
                st2.push(t2);
                if(t1->val!=t2->val) return false;
                t1=t1->left;
                t2=t2->left;
            }
            else{
                t1=st1.top();
                st1.pop();
                t2=st2.top();
                st2.pop();
                if(t1->val !=t2->val) return false;
                t1=t1->right;
                t2=t2->right;
            }
        }
        return true;
    }
};
