/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        unordered_map <Node*,Node*> location;
        Node* copy = new Node(head->val);
        location[head]=copy;
        Node* currentOriginal=head->next;
        Node* currentNew=copy;
        while(currentOriginal != nullptr){
            Node* temp=new  Node(currentOriginal->val);
            currentNew->next=temp;
            currentNew=currentNew->next;
            location[currentOriginal]=currentNew;
            currentOriginal=currentOriginal->next;
        }
        currentOriginal=head;
        currentNew=copy;
        while(currentOriginal != nullptr){
            if(currentOriginal->random==nullptr) currentNew->random=nullptr;
            else currentNew->random=location[currentOriginal->random];
            currentOriginal=currentOriginal->next;
            currentNew=currentNew->next;
        }
        return copy;
    }
};
