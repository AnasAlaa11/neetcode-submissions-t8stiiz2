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
    void reorderList(ListNode* head) {
        unordered_map<ListNode*,ListNode*> pre;
        ListNode* p;
        ListNode* q;
        ListNode* nxt;
        p=head;q=head;
        while(p){
            pre[p->next]=p;
            p=p->next;
        }
        p = pre[nullptr];
        while(q!=p&& pre[p] != q){
            nxt=q->next;
            q->next=p;
            p->next=nxt;
            p=pre[p];
            q=nxt;
        }
        p->next = nullptr;
    }
};
