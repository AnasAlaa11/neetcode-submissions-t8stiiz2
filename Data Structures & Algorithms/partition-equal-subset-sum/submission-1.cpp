class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int temp= accumulate( nums.begin(), nums.end(), 0);
        for(int i=0;i<nums.size();i++){
            int current=0;
            int sum=temp;
            for(int j=0;j<nums.size();j++){
                if(i==j) continue;
                current+=nums[j];
                sum-=nums[j];
                if(sum==current) return true;
                else if(current>sum){
                    sum+=nums[j];
                    current-=nums[j];
                }
            }
        }
        return false;
    }
};
