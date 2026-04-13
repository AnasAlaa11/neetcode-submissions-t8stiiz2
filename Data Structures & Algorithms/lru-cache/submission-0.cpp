class LRUCache {
private:
    struct ListNode {
        int key;
        int val;
        ListNode *next;
        ListNode *prev;
        ListNode(int k, int v) : val(v), key(k),next(nullptr), prev(nullptr) {}
    };
    unordered_map<int , ListNode *> dict;
    ListNode * head;
    ListNode * tail;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(dict.count(key)){
            update(key,dict[key] -> val);
            return dict[key] -> val;
        } 
        return -1;
    }
    
    void update(int key, int value){
        ListNode* node = dict[key];
        node->val=value;

        node->prev->next=node->next;
        node->next->prev=node->prev;

        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
        return;
    }
    void put(int key, int value) {
        if(dict.count(key)){
            update(key,value);
        } 
        else{
            ListNode * newNode= new ListNode(key,value);
            dict[key]=newNode;

            newNode->next=head->next;
            newNode->prev=head;
            head->next->prev=newNode;
            head->next=newNode;
         
        }
        if(dict.size()>capacity){
            ListNode * lruNode=tail->prev;
            dict.erase(lruNode->key);
            lruNode->prev->next=tail;
            tail->prev=lruNode->prev;

            delete lruNode;
        }
    }
};
