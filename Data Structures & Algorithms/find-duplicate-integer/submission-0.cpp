class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set <int> hist;
        for(int i=0;i<nums.size();i++){
            if(hist.count(nums[i])) return nums[i];
            hist.insert(nums[i]);
        }
        return 0;
    }
};
