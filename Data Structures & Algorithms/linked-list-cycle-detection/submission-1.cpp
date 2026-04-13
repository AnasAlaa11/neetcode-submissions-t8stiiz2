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
    bool hasCycle(ListNode* head) {
        int visit=INT_MIN;
        ListNode* p=head;
        ListNode* q=nullptr;
        while(p&&p->val!=visit){
            p->val=visit;
            p=p->next;
        }
        if(!p) return false;
        return true;
    }
};
