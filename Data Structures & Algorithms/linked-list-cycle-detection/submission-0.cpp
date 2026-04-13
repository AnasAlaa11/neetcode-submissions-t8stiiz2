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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> visit;
        ListNode * p;
        p=head;
        while(p){
            if(visit.count(p)) return true;
            visit.emplace(p);
            p=p->next;
        }
        return false;
    }
};

