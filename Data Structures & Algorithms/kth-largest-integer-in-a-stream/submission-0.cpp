class KthLargest {
public:
    int myK;
    priority_queue<int> q;
    stack<int>s;
    KthLargest(int k, vector<int>& nums) {
        myK=k;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
    }
    
    int add(int val) {
        q.push(val);
        int res;
        for(int i=0;i<myK-1;i++){
            s.push(q.top());
            q.pop();
        }
        res=q.top();
        for(int i=0;i<myK-1;i++){
            q.push(s.top());
            s.pop();
        }
        return res;
    }
};
