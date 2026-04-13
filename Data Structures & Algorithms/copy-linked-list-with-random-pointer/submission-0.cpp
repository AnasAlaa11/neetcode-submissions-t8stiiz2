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
        Node* copy = new Node(head->val);
        Node* currentOriginal=head->next;
        Node* currentNew=copy;
        while(currentOriginal != nullptr){
            Node* temp=new  Node(currentOriginal->val);
            
            currentNew->next=temp;
            currentNew=currentNew->next;
            currentOriginal=currentOriginal->next;
        }
        currentOriginal=head;
        currentNew=copy;
        while(currentOriginal != nullptr){
            int count=0;
            if(currentOriginal->random==nullptr) currentNew->random=nullptr;
            else{
                Node* value=currentOriginal->random;
                Node* temp=head;
                while(temp!=nullptr&&temp!=value){
                    temp=temp->next;
                    count++;
                }
                Node* t_random=copy;
                while(count){
                    count--;
                    t_random=t_random->next;
                }
                currentNew->random=t_random;
            }
            currentNew=currentNew->next;
            currentOriginal=currentOriginal->next;

        }
        return copy;
    }
};
