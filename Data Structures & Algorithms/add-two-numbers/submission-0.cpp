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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res;
        res = new ListNode;
        ListNode* last;
        int re=0;
        res->val=(int)((re+(l1->val)+(l2->val))%10);
        re=(re+(l1->val)+(l2->val))/10;
        last=res;
        l1=l1->next;l2=l2->next;
        while(l1&&l2){
            ListNode* t;
            t = new ListNode;
            t->val=(re+(l1->val)+(l2->val))%10;
            t->next=nullptr;
            re=(re+(l1->val)+(l2->val))/10;
            last->next=t;
            last=t;
            l1=l1->next;l2=l2->next;
        }
        while(l1){
            ListNode* t;
            t = new ListNode;
            t->val=(re+(l1->val))%10;
            t->next=nullptr;
            re=(re+(l1->val))/10;
            last->next=t;
            last=t;
            l1=l1->next;
        }        
        while(l2){
            ListNode* t;
            t = new ListNode;
            t->val=(re+(l2->val))%10;
            t->next=nullptr;
            re=(re+(l2->val))/10;
            last->next=t;
            last=t;
            l2=l2->next;
        }
        if(re){
            ListNode* t;
            t = new ListNode;
            t->val=re;
            t->next=nullptr;
            last->next=t;
        }
        return res;
    }
};