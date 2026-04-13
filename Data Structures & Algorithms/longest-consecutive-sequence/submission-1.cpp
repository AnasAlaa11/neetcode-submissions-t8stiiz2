class Solution {
public:
int longestConsecutive(vector<int>& nums) {
    priority_queue<int> s;
    for(int i=0;i<nums.size();i++){
        s.push(nums[i]);
    }
    if(s.empty()) return 0;
    int count=0;
    vector<int> v;
    int r=s.size();
    for(int i=0;i<r;i++){
        int j=s.top();
        s.pop();
        if(s.empty()) {
            count++;
            v.push_back(count);
            break;
        }
        if((!s.empty())&&(j==(s.top()+1))){
            count++;
            continue;
        }
        else if((!s.empty())&&(j==(s.top()))) continue;
        v.push_back(count+1);
        count=0;
    }
    return *(max_element(v.begin(),v.end()));
}
};
