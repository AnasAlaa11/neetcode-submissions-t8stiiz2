/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        unordered_map<Node*,Node*> m;
        queue<Node*> originQ;
        Node* root=new Node(node->val);
        originQ.push(node);
        m[node]=root;
        while(!originQ.empty()){
            Node* tO=originQ.front();
            Node* tN=m[tO];
            originQ.pop();
            for(int i=0;i<tO->neighbors.size();i++){
                if(!m[tO->neighbors[i]]){
                    Node* newNode=new Node(tO->neighbors[i]->val);
                    m[(tO->neighbors[i])]=newNode;
                    originQ.push(tO->neighbors[i]);
                }
                tN->neighbors.emplace_back(m[tO->neighbors[i]]);
            }
        }
        return root;
    }
};
