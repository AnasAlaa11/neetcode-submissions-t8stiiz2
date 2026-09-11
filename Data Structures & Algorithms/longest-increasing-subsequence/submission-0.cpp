class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector <int> dp(n,1);
        int res=0;
        for(int i=0;i<n;i++){
            int maximum=0;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    maximum=max(maximum,dp[j]+1);
                }
            }
            dp[i]=maximum;
            res=max(res,maximum+1);
        }
        return res;
    }
};
