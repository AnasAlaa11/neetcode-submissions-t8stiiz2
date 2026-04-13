class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(auto it=0;it!=nums.size();it++){
            for(auto it1=it+1;it1!=nums.size();it1++){
                if(nums[it]+nums[it1]==target) return {it,it1};
            }
        }
    }
};
