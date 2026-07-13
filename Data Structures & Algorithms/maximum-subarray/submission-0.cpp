class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxNum=INT_MIN;
        int temp=0;
        for (int i=0;i<nums.size();i++){
            temp +=nums[i];
            if(temp<0) temp=0;
            else{
                maxNum=max(maxNum,temp);
            }
            maxNum=max(maxNum,nums[i]);
        }
        return maxNum;
    }
};
