/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> pos;
        ListNode* p=head;
        while(p){
            pos.push_back(p);
            p=p->next;
        }
        if(pos.size()==1) return nullptr;
        int target=pos.size()-n;
        if(target==0){
            head=pos[target]->next;
        }
        else{
            pos[target-1]->next=pos[target]->next;
        }
        return head;
    }
};
