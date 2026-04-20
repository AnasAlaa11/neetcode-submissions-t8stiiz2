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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size()==0) return nullptr;
        if(inorder.size()==1){
            TreeNode* n= new TreeNode(inorder[0]);
            return n;
        } 
        TreeNode* root=new TreeNode(preorder[0]);
        int i=0;
        int j=1;
        while(inorder[i]!=preorder[0]){
            i++;
        }
        vector<int> newInorder(inorder.begin(),inorder.begin()+i);
        vector<int> newPreorder(preorder.begin()+j,preorder.begin()+j+newInorder.size());
        i++;
        int r=j+newInorder.size();

        root->left=buildTree(newPreorder,newInorder);
        if(i<=inorder.size()-1&& r<=preorder.size()-1){
            newInorder.assign(inorder.begin()+i,inorder.end());
            newPreorder.assign(preorder.begin()+r,preorder.end());
            root->right=buildTree(newPreorder,newInorder);
        }
        return root;
    }
};
