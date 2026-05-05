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
            for(Node* neighbor : tO->neighbors){
                if(!m.count(neighbor)){
                    Node* newNode=new Node(neighbor->val);
                    m[neighbor]=newNode;
                    originQ.push(neighbor);
                }
                tN->neighbors.emplace_back(m[neighbor]);
            }
        }
        return root;
    }
};
