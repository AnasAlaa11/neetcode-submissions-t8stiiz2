class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> dpP(n,0);
        vector<int> dpN(n,0);
        dpP[n-1]=nums[n-1];
        dpN[n-1]=nums[n-1];
        int res=nums[n-1];
        for (int i=n-2;i>=0;i--){
            int p=max(nums[i]*dpP[i+1],nums[i]*dpN[i+1]);
            int n=min(nums[i]*dpP[i+1],nums[i]*dpN[i+1]);
            dpP[i]=max(nums[i],p);
            dpN[i]=min(nums[i],n);
            res=max(res,dpP[i]);
        }
        return res;
    }
};
