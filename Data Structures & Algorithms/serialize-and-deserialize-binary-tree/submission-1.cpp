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

class Codec {
public:
    void preorder(TreeNode* t, string & s){
        if(t==nullptr){
            s+="+";
            s+=",";
            return;
        } 
        s+=to_string(t->val)+",";
        preorder(t->left,s);
        preorder(t->right,s);
    }
    void build(string data,vector<int>& res){
        string split = "";
        for(char c : data){
            if(c != ','){
                split += c;
            }
            else {
                if(split == "+") res.emplace_back(INT_MIN);
                else res.emplace_back(stoi(split));
                split = "";
            }
        }
    }
    TreeNode* buildTree(vector <int>& preorder, int &i){
        if(preorder[i]==INT_MIN){
            i++;
            return nullptr;   
        } 
        TreeNode* root=new TreeNode(preorder[i]);
        i++;
        if(i<preorder.size()){
            root->left=buildTree(preorder,i);
            root->right=buildTree(preorder,i);
        }
        return root;
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "*";
        string s="";
        preorder(root,s);
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {     
        if(data=="*") return nullptr;
        TreeNode* root;
        vector <int> preorder;
        build(data,preorder);
        int i=0;
        root=buildTree(preorder,i);
        return root;

    }
};
