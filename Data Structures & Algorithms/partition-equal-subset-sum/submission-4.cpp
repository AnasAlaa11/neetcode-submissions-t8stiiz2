class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate( nums.begin(), nums.end(), 0);
        if(sum%2!=0) return false;
        int target=sum/2;
        unordered_set<int> dp;
        dp.insert(0);
        for(int i=nums.size()-1;i>=0;i--){
            unordered_set<int> next_dp;
            for(auto n: dp){
                int t=n+nums[i];
                if(t==target) return true;
                next_dp.insert(t);
            }
            dp.insert(next_dp.begin(), next_dp.end());
        }
        return false;
    }
};
